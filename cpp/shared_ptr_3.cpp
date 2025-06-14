#include <memory>
#include <print>

struct Obj
{
  int value = 42;

  void fn()
  {
    std::println("ryukendo. {}", this->value);
  }
};

int main()
{
  std::shared_ptr<Obj> ptr = nullptr;

  ptr->fn();
}