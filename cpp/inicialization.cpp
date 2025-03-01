#include <iostream>
#include <vector>

int main()
{
    // inicialização direta
    // para tipos primitivos, é funcionalmente igual a inicialização por atribuição
    int a(10);

    // inicialização uniforme. C++11
    // evita narrowing conversions (conversões implícitas e por vezes imprecisas)
    // suporta inicialização de listas e vetores de forma eficiente
    std::vector<int> xs{1, 2, 3};

    // inicialização por valor
    // mesma sintaxe que inicialização por atribuição
    // no entanto, é para inicializar variáveis de objetos.
    // o valor invoca o construtor ou o operador de atribuição do tipo
    std::vector<int> v = {1, 2, 3};

    // inicialização com ponteiro (new)
    // memória alocada dinamicamente no heap
    // deve ser liberada com delete
    // útil quando não sabemos o tamanho em compile time.
    int *ptr = new int(10);

    // inicialização com auto
    // inferência de tipo
    auto a = 10;
    // utilizado para lidar com tipos complexos, como iteradores.

    return 0;
}