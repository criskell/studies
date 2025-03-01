#include <iostream>

int main()
{
    // normalmente essa porra desaparecia no final da expressao
    // no entanto, const refs estendem o tempo de vida do temporário
    // até sair do escopo
    // chamamos isso de materialização de temporários
    const int &x = int(42);

    std::cout << x << std::endl;

    // isso nn é permitido
    // um temporário é um rvalue
    // precisamos de um lvalue para utilizar o operador unário &
    // caso não tivesse isso ainda,
    // o temporário int(42) desaparecia no final da expressão
    // e retornaria um endereço de memória inválido
    // int *y = &int(42);

    // referências constantes podem se ligarem a temporários
}