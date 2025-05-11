#include <iostream>
#include <memory>

struct Test
{
    Test() { std::cout << "Constructor" << std::endl; }
    ~Test() { std::cout << "Destructor" << std::endl; }
    void do_something() { std::cout << "Doing something..." << std::endl; }
};

int main()
{
    std::unique_ptr<Test> a = std::make_unique<Test>();
    a->do_something();
}