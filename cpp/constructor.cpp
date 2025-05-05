#include <iostream>

class Person
{
public:
    // ": name(name), age(age)" define uma member initializer list.
    // inicializa os atributos da classe antes do construtor ser executado.
    Person(std::string name, int age) : name(name), age(age)
    {
    }

private:
    std::string name;
    int age;
};

class ExampleConst
{
public:
    // Obrigatório ter essa lista.
    ExampleConst(int value) : number(value)
    {
    }

    int readNumber()
    {
        return number;
    }

private:
    const int number;
};

int main()
{
    ExampleConst example1(10); // Inicialização direta
    std::cout << example1.readNumber() << std::endl;

    ExampleConst example2 = ExampleConst(20); // Inicialização por cópia
    std::cout << example2.readNumber() << std::endl;

    ExampleConst example3{30}; // Inicialização uniforme
    std::cout << example3.readNumber() << std::endl;
}