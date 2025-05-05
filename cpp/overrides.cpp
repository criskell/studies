#include <iostream>

class A
{
public:
    void show()
    {
        std::cout << "A" << std::endl;
    }
};

class B : public A
{
public:
    void show()
    {
        std::cout << "B" << std::endl;
    }
};

class C
{
public:
    virtual void show()
    {
        std::cout << "C" << std::endl;
    }
};

class D : public C
{
public:
    void show()
    {
        std::cout << "D" << std::endl;
    }
};

int main()
{
    B b;
    b.show();

    A *a = &b;
    a->show();

    D d;
    d.show();

    C *c = &d;
    c->show();
}