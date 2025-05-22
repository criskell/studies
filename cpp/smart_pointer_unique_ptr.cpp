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
     * O que são smart pointers?
     *  Classes da STL que gerenciam automaticamente a memória.
     *
     * O que é unique ptr?
     *  São ponteiros exclusivos onde pode ter apenas um dono do recurso.
     *  - Quando unique ptr sai do escopo, a memória é automaticamente liberada.
     *  - Impede que múltiplos ponteiros tentem liberar o mesmo recurso.
     */
    std::unique_ptr<int> ptr = std::make_unique<int>(100);
    std::cout << "Valor : " << *ptr << std::endl;

    // int *ptr = new int;
    // *ptr = 42;
    // std::cout << "Valor : " << *ptr << std::endl;

    return 0;
}