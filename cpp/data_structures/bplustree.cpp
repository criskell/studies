#include <algorithm>
#include <cassert>
#include <cstddef>
#include <functional>
#include <memory>
#include <optional>
#include <print>
#include <string>
#include <utility>
#include <vector>

template <typename Key, typename Value, std::size_t Order = 4>
class BPlusTree {
  static_assert(Order >= 3, "Order must be greater or equal to 3.");

 private:
  struct Node {
    bool is_leaf;
    std::vector<Key> keys;
    std::vector<std::unique_ptr<Node>> children;  // is_leaf == false
    std::vector<Value> values;                    // is_leaf == true

    Node* parent = nullptr;  // Ponteiro fraco. Não OWNING.
    Node* next = nullptr;    // Ligação entre folhas.

    explicit Node(bool leaf) : is_leaf(leaf) {}

    [[nodiscard]] bool is_full() const { return keys.size() >= Order - 1; }
  };

  std::unique_ptr<Node> root_;

  [[nodiscard]] Node* find_leaf(const Key& key) const {
    Node* node = root_.get();

    while (node && !node->is_leaf) {
      std::size_t idx =
          std::upper_bound(node->keys.begin(), node->keys.end(), key) -
          node->keys.begin();
      node = node->children[idx].get();
    }

    return node;
  }

  void insert_in_leaf(Node* leaf, const Key& key, const Value& value) {
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    std::size_t pos = static_cast<std::size_t>(it - leaf->keys.begin());

    if (it != leaf->keys.end() && *it == key) {
      leaf->values[pos] = value;
      return;
    }

    leaf->keys.insert(it, key);
    leaf->values.insert(leaf->values.begin() + pos, value);
  }

  void split_leaf(Node* leaf) {
    auto new_leaf = std::make_unique<Node>(true);

    std::size_t mid = leaf->keys.size() / 2;

    new_leaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
    new_leaf->values.assign(leaf->values.begin() + mid, leaf->values.end());

    leaf->keys.resize(mid);
    leaf->values.resize(mid);

    new_leaf->next = leaf->next;
    leaf->next = new_leaf.get();

    Key promoted_key = new_leaf->keys.front();

    if (!leaf->parent) {
      auto new_root = std::make_unique<Node>(false);
      new_root->keys.push_back(promoted_key);

      new_root->children.push_back(std::move(root_));
      new_root->children.push_back(std::move(new_leaf));

      new_root->children[0]->parent = new_root.get();
      new_root->children[1]->parent = new_root.get();

      root_ = std::move(new_root);
    } else {
      insert_in_parent(leaf, promoted_key, std::move(new_leaf));
    }
  }

  void insert_in_parent(Node* left,
                        const Key& key,
                        std::unique_ptr<Node> right) {
    Node* parent = left->parent;
    auto it = std::upper_bound(parent->keys.begin(), parent->keys.end(), key);
    std::size_t pos = static_cast<std::size_t>(it - parent->keys.begin());

    parent->keys.insert(it, key);
    parent->children.insert(parent->children.begin() + pos + 1,
                            std::move(right));
    parent->children[pos + 1]->parent = parent;

    if (parent->is_full())
      split_internal(parent);
  }

  void split_internal(Node* node) {
    auto new_internal = std::make_unique<Node>(false);
    std::size_t mid_idx = node->keys.size() / 2;

    Key promoted_key = node->keys[mid_idx];
    new_internal->keys.assign(node->keys.begin() + mid_idx + 1,
                              node->keys.end());
    node->keys.resize(mid_idx);

    new_internal->children.assign(
        std::make_move_iterator(node->children.begin() + mid_idx + 1),
        std::make_move_iterator(node->children.end()));
    node->children.resize(mid_idx + 1);

    for (auto& child : new_internal->children)
      child->parent = new_internal.get();

    if (!node->parent) {
      auto new_root = std::make_unique<Node>(false);

      new_root->keys.push_back(promoted_key);
      new_root->children.push_back(std::move(root_));
      new_root->children.push_back(std::move(new_internal));

      new_root->children[0]->parent = new_root.get();
      new_root->children[1]->parent = new_root.get();

      root_ = std::move(new_root);
    } else {
      insert_in_parent(node, promoted_key, std::move(new_internal));
    }
  }

 public:
  BPlusTree() : root_(std::make_unique<Node>(true)) {}

  void insert(const Key& key, const Value& value) {
    Node* leaf = find_leaf(key);

    assert(leaf && "A árvore deve ter pelo menos uma folha.");

    insert_in_leaf(leaf, key, value);
    if (leaf->is_full())
      split_leaf(leaf);
  }

  std::optional<Value> get(const Key& key) const {
    Node* leaf = find_leaf(key);
    if (!leaf)
      return std::nullopt;

    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    std::size_t pos = static_cast<std::size_t>(it - leaf->keys.begin());

    if (it != leaf->keys.end() && *it == key)
      return leaf->values[pos];
    return std::nullopt;
  }

  template <typename Func>
  void scan(const Key& start_key, Func func) const {
    Node* leaf = find_leaf(start_key);

    while (leaf) {
      for (std::size_t i = 0; i < leaf->keys.size(); ++i) {
        if (leaf->keys[i] >= start_key) {
          if (!func(leaf->keys[i], leaf->values[i]))
            return;
        }
      }
      leaf = leaf->next;
    }
  }
};

int main() {
  BPlusTree<int, std::string, 4> tree;

  for (int i = 1; i <= 10; ++i) {
    tree.insert(i, "v" + std::to_string(i));
  }

  for (int k = 1; k <= 10; ++k) {
    auto v = tree.get(k);

    if (v) {
      std::println("{} => {}", k, *v);
    }

    tree.scan(5, [](int k, const std::string& v) {
      std::println("{}: {}", k, v);
      return true;
    });
  }
}