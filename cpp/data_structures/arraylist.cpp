#include <iostream>
#include <stdexcept>

/**
 * An array list is a dynamic list based on an contiguous fixed array that is allocated on the heap.
 * 
 * It offers better cache locality and faster access to random items when compared to linked lists.
 * But it makes rapid changes difficult without moving elements in memory.
 *
 * ## Time complexity
 *
 * - get: O(1). We are storing sequentially and retrieving elements by index.
 * - insert/remove_at: O(n). Insertions and removals in the middle of a list require shifting elements.
 */
template <typename T>
class ArrayList {
private:
  T* data;
  size_t capacity;
  size_t size;

  void resize(size_t new_capacity) {
    T* new_data = new T[new_capacity];

    for (size_t i = 0; i < size; i++) {
      new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

public:
  ArrayList(size_t initial_capacity = 100) : capacity(initial_capacity), size(0) {
    data = new T[capacity];
  }

  ~ArrayList() {
    delete[] data;
  }

  void add(const T& value) {
    if (size == capacity) {
      resize(capacity * 2);
    }

    data[size++] = value;
  }

  T& get(size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");

    return data[index];
  }

  void remove_at(size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");

    for (size_t i = index; i < size - 1; i++) {
      data[i] = data[i + 1];
    }

    size--;
  }

  size_t get_size() {
    return size;
  }
};

int main() {
  ArrayList<int> list;

  list.add(10);
  list.add(20);
  list.add(30);

  for (size_t i = 0; i < list.get_size(); i++) {
    std::cout << list.get(i) << std::endl;
  }

  list.remove_at(1);

  for (size_t i = 0; i < list.get_size(); i++) {
    std::cout << list.get(i) << std::endl;
  }

  return 0;
}