#include <print>
#include <string>

// Args&&... args - Parâmetro pack com forwarding references.
template <typename T, typename... Args>
T *make(Args &&...args)
{
    // std::forward preserva o tipo original (r-value, const, etc.).
    return new T(std::forward<Args>(args)...);
}

class Person
{
public:
    Person(const std::string &name, int age)
    {
        std::println("Person(name={}, age={})", name, age);
    }
};

int main()
{
    auto p = make<Person>("criskell", 20);
    delete p;
}