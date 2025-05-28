#include <print>
#include <new>

struct Test
{
    Test() { std::println("Constructor called."); }
    ~Test() { std::println("Destructor called."); }
};

int main()
{
    // `alignas` garante que um objeto esteja alinhado corretamente na memória.
    // significa colocar o objeto em um endereço de memória que é múltiplo de algum número.
    //  -> compatibilidade, pode gerar undefined behaviour
    //  -> desempenho
    //     -> cpu acessa memória em blocos (palavras) geralmente
    //     -> se tiver desalinhado, pode precisar de 2 leituras por exemplo
    alignas(Test) char buffer[sizeof(Test)];
    Test *t = new (buffer) Test();
    t->~Test();
}