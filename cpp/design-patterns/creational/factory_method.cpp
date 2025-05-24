#include <print>

class Product
{
public:
    // Defines a pure virtual function.
    // When a class has a pure virtual function, it becomes an abstract class.
    // An abstract class cannot be instantiated, only extended by its subclasses.
    virtual void use() = 0;

    virtual ~Product() = default;
};

class ProductA : public Product
{
public:
    void use() override
    {
        std::println("Using ProductA.");
    }
};

class ProductB : public Product
{
public:
    void use() override
    {
        std::println("Using ProductB.");
    }
};

class Creator
{
public:
    // We define an abstract method (as a pure virtual function) that will be extended by the subclasses
    // that extend the abstract `Creator` class.
    virtual Product *createProduct() = 0;

    void operate()
    {
        Product *product = createProduct();
        product->use();
        delete product;
    }

    virtual ~Creator() = default;
};

class CreatorA : public Creator
{
public:
    Product *createProduct() override
    {
        return new ProductA();
    }
};

class CreatorB : public Creator
{
public:
    Product *createProduct() override
    {
        return new ProductB();
    }
};

int main()
{
    // We abstract the factory in such a way that we only know that the type of object returned
    // will be a subtype of the type of object we are interested in.
    Creator *creator = new CreatorA();
    creator->operate();

    delete creator;

    // We are dealing with another factory that will return another concrete type,
    // but which is a subtype of the Product type we are interested in.
    creator = new CreatorB();
    creator->operate();

    delete creator;
}