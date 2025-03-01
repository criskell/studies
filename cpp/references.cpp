#include <iostream>

void foo(const int &x)
{
    std::cout << x;
}

int main()
{
    // referencias são ponteiros constantes (não podem mudar para onde apontam)
    // - com indireção automática, não precisamos fazer desreferenciamento com o operador *.
    // - precisam ser inicializadas com valor não nulo
    // - não é possível fazer aritmética como aritmética de ponteiros
    // - não é possível pegar o endereço nem o tamanho de uma referência. ao tentar, irá retornar informações do valor referenciado.

    foo(int(5));
}