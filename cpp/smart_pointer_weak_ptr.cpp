#include <iostream>
#include <memory>

void *operator new(size_t size)
{
    std::cout << "Alocando memória: " << size << std::endl;
    return malloc(size);
}

void operator delete(void *ptr)
{
    std::cout << "Liberando memória" << std::endl;
    free(ptr);
}

int main()
{
    /**
     * O que é weak ptr?
     * Similar ao shared ptr, mas não aumenta a contagem de referência.
     * Ponteiro fraco.
     * Não impede a liberação de memória.
     */
    std::unique_ptr<int> ptr = std::make_unique<int>(100);
    std::cout << "Valor : " << *ptr << std::endl;

    // int *ptr = new int;
    // *ptr = 42;
    // std::cout << "Valor : " << *ptr << std::endl;

    return 0;
}