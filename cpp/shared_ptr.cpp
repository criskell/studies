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
    std::shared_ptr<Test> a = std::make_shared<Test>();

    {
        std::shared_ptr<Test> b = a;
        std::cout << "References: " << b.use_count() << std::endl;
    }

    std::cout << "References: " << a.use_count() << std::endl;
}