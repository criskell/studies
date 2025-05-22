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
     * O que é shared ptr?
     * Vários ponteiros podem compartilhar o mesmo recurso.
     * Mantém uma reference count.
     * Libera a memória quando essa contagem é zero.
     */
    std::shared_ptr<int> ptr = std::make_shared<int>(100);
    std::shared_ptr<int> ptr2 = ptr; // aumenta a contagem em +1.

    std::cout << "Valor: " << *ptr << ", Contagem de refs.: " << ptr.use_count() << std::endl;

    {
        std::shared_ptr<int> ptr3 = ptr; // aumenta a contagem em +1.
        std::cout << "Valor: " << *ptr << ", Contagem de refs.: " << ptr.use_count() << std::endl;
    }

    std::cout << "Valor: " << *ptr << ", Contagem de refs.: " << ptr.use_count() << std::endl;

    return 0;
}