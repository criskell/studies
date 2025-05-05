#include <iostream>

int main()
{
    // tentando criar uma referência nula
    // converter ponteiro null para int*
    // desreferenciar o ponteiro nulo
    // criar uma referência com base no valor do ponteiro nulo, oq provavelmente vai falhar.
    int &x = *static_cast<int *>(nullptr);
    std::cout << x << std::endl;
    return 0;
}