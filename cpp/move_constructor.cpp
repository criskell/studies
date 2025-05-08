#include <iostream>
#include <utility>
#include <cstring>

struct MyStruct
{
    char *data;

    MyStruct(const char *s)
    {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    MyStruct(MyStruct &&other)
    {
        data = other.data;
        other.data = nullptr;
    }

    ~MyStruct()
    {
        delete[] data;
    }
};

int main()
{
    MyStruct v1("hello, world!");
    std::cout << v1.data << std::endl;

    MyStruct v2 = std::move(v1);
    std::cout << v2.data << std::endl;
}