#include <memory>

int main()
{
    std::allocator<int> alloc;

    int *p = alloc.allocate(10); // alocar 10 inteiros
    alloc.deallocate(p, 10);     // libera a memória

    return 0;
}