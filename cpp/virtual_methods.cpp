#include <iostream>

class Animal
{
public:
    // Metódos virtuais são métodos sobrescritos pela classe derivada.
    virtual void speak()
    {
        std::cout << "Animal speaks" << std::endl;
    }

    virtual void teste()
    {
        std::cout << "Teste Animal" << std::endl;
    }

    void falar()
    {
        std::cout << "Animal fala" << std::endl;
    }
};

class Dog : public Animal
{
public:
    // `override` é um tipo especial de identificador que serve para:
    // - informar que isso é um método virtual que está sobrescrevendo um método virtual da classe base.
    // - informar ao compilador que é uma sobrescrita e então impeça alteração/adição de novos métodos
    // que você pensa que é uma sobrescrita.
    void speak() override
    {
        std::cout << "Dog speaks" << std::endl;
    }

    void falar()
    {
        std::cout << "Cachorro fala" << std::endl;
    }

    void teste()
    {
        std::cout << "Teste cachorro" << std::endl;
    }
};

int main()
{
    Animal *a = new Dog();
    a->speak();
    a->falar();
    a->teste();
}