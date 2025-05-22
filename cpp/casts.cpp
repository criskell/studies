#include <print>

int main()
{
    int x = 42;
    // static_cast só permitirá conversões entre tipos relacionados.
    double y = static_cast<double>(x);

    class Base
    {
    };

    class Derived : public Base
    {
    };

    Derived *d = new Derived();
    // outro exemplo: converter ponteiros com herança.
    Base *b = static_cast<Base *>(d);

    void *v = d;
    Derived *d2 = static_cast<Derived *>(v);

    int z = 123;
    char *p = reinterpret_cast<char *>(&z); // trata os bits de x como caracteres

    uintptr_t i = reinterpret_cast<uintptr_t>(p);

    double dbl = 3.1415;
    int *asInt = reinterpret_cast<int *>(&dbl);

    std::print("Integer: {}", *asInt);
}