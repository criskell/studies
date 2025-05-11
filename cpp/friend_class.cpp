#include <iostream>

class Engine
{
private:
    int power = 100;

    friend class Car;
};

class Car
{
public:
    void showPower(const Engine &engine)
    {
        std::cout << "Power: " << engine.power << std::endl;
    }
};

int main()
{
    Engine e;
    Car c;

    c.showPower(e);
}