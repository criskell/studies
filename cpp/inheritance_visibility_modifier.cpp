#include <iostream>

class B1
{
public:
    void show()
    {
        std::cout << "B1.show()" << std::endl;
    }
};

// Seria D1: private B1
class D1 : B1
{
public:
    void callShow()
    {
        show();
    }
};

class B2
{
public:
    void show()
    {
        std::cout << "B2.show()" << std::endl;
    }
};

class D2 : protected B2
{
public:
    void callShow()
    {
        show();
    }
};

class D3 : D1
{
public:
    void test()
    {
        // Não posso
        // show();
    }
};

class D4 : D2
{
public:
    void test()
    {
        // Posso
        show();
    }
};

class B4
{
public:
    void show()
    {
        std::cout << "B4.show()" << std::endl;
    }
};

class D5 : public B4
{
public:
    void callShow()
    {
        show();
    }
};

int main()
{
    D1 d1;

    d1.callShow();
    // Inacessível:
    // d1.show()

    D5 d5;
    d5.show();
}