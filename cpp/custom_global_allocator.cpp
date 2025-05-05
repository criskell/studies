#include <iostream>

// retorna um ponteiro genérico
void *operator new(size_t size)
{
    std::cout << "Alocando n bytes : " << size << std::endl;
    return malloc(size);
}

void operator delete(void *ptr)
{
    std::cout << "Liberando memória" << std::endl;
    free(ptr);
}

int main()
{
    int *p = new int;
    *p = 42;
    std::cout << *p << std::endl;
    delete p;
    return 0;
}