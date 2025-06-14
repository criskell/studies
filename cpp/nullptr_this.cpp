#include <memory>
#include <print>

class Foo
{
public:
  void bar1()
  {
    std::println("Called bar1");
  }

  void bar2()
  {
    std::println("Called bar2");
  }
};

int main()
{
  Foo *foo = nullptr;
  foo->bar1();
  foo->bar2();
}