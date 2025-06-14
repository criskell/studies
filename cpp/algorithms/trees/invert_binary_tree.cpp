#include <iostream>
#include <memory>
#include <cmath>
#include <print>
#include <queue>
#include <string>

void print_spaces(int count)
{
  for (int i = 0; i < count; ++i)
    std::print(" ");
}

struct TreeNode
{
  int value;
  std::shared_ptr<TreeNode> left, right;

  TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}

  void invert()
  {
    auto temp = left;

    left = right;
    right = temp;
  }

  int tree_height()
  {
    int left_height = left ? left->tree_height() : 0;
    int right_height = right ? right->tree_height() : 0;

    return 1 + std::max(left_height, right_height);
  }

  void print()
  {
    int height = tree_height();
    int max_width = std::pow(2, height) - 1;

    std::queue<std::shared_ptr<TreeNode>> q;
    q.push(std::make_shared<TreeNode>(*this));

    int x = height + 2;

    for (int level = 0; level < height; ++level)
    {
      int level_nodes = std::pow(2, level);

      print_spaces(x);
      x = x - 1;

      for (int i = 0; i < level_nodes; ++i)
      {
        auto node = q.front();
        q.pop();

        if (node)
        {
          std::print("{}", node->value);
          q.push(node->left);
          q.push(node->right);
        }
        else
        {
          std::print(" ");
          q.push(nullptr);
          q.push(nullptr);
        }

        print_spaces(3);
      }

      std::println("");

      if (level < height - 1)
      {
        print_spaces(x);
        x--;

        for (int i = 0; i < level_nodes; ++i)
        {
          auto left = q.front();
          q.pop();
          auto right = q.front();
          q.pop();

          if (left)
            std::print("/");
          else
            std::print(" ");

          print_spaces(1);

          if (right)
            std::print("\\");
          else
            std::print(" ");

          print_spaces(x * 2 - 2);
          q.push(left);
          q.push(right);
        }

        std::println("");
      }
    }
  }
};

int main()
{
  auto root = std::make_shared<TreeNode>(1);

  root->left = std::make_shared<TreeNode>(2);
  root->right = std::make_shared<TreeNode>(3);
  root->left->left = std::make_shared<TreeNode>(4);
  root->left->right = std::make_shared<TreeNode>(5);
  root->left->right->right = std::make_shared<TreeNode>(5);

  root->print();
  // root->invert();
  // root->print();
}