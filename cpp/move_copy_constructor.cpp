#include <print>

class Test
{
public:
    Test(const std::string &name) { std::println("Cópia."); }
    Test(const std::string &&name) { std::println("Movimento."); }
};

int main()
{
    std::string name = "criskell";

    Test test1(name);
    Test test2(std::move(name));
}