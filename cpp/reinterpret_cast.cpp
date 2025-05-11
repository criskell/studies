#include <iostream>

int main()
{
    float f = 3.14f;
    int i = 123;

    // reinterpret_cast muda a interpretação dos bits de um tipo.
    int *ptr_i = reinterpret_cast<int *>(&f);
    std::cout << "Float as integer: " << *ptr_i << std::endl;

    float *ptr_f = reinterpret_cast<float *>(&i);
    std::cout << "Integer as float: " << *ptr_f << std::endl;
}