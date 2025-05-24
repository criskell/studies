#include <print>
#include <memory>

class Person
{
public:
    Person(const std::string &name) : m_name(name)
    {
        std::println("Created {}", m_name);
    }

    ~Person()
    {
        std::println("Destroyed {}", m_name);
    }

private:
    std::string m_name;
};

int main()
{
    std::shared_ptr<Person> p1 = std::make_shared<Person>("criskell");

    {
        std::shared_ptr<Person> p2 = p1;
        std::println("Inside block.");
    }

    std::println("Main end.");
    return 0;
}