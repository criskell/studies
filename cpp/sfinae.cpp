#include <print>
#include <utility>
#include <vector>
#include <type_traits>

// `auto` indica que o tipo de retorno será deduzido mas com uma dica após o "->" (chamamos de trailing return type).
// (int) ajuda na resolução do overload e para o SFINAE funcionar.
// std::declval<T>() simula um valor do tipo T mesmo que não exista.
// decltype(expr1, expr2) retorna expr2 somente se a expr1 for válida.
// se o tipo não for válido no retorno, o compilador descarta essa especialização.
// void() é uma chamada a um construtor padrão do tipo `void` (mesmo que esse construtor não exista em runtime).
// não usamos apenas void pois o decltype espera uma expressão.
// outro exemplo com decltype: "decltype(42, true)" nos retorna o tipo bool.
// "decltype(42, void())" nos retorna o tipo void.

// int é necessário para o compilador escolher a versão mais específica. caso contrário não saberia se o overload correto era esse
// ou o de baixo. ele sempre escolhe a melhor correspondência.
template <typename T, typename = std::enable_if<std::is_same_v<decltype(std::declval<T>().size()), std::size_t>>>
void test(int)
{
    std::println("Tem size()");
}

template <typename T>
void test(...)
{
    std::println("Não tem size()");
}

int main()
{
    test<int>(42);
    test<std::string>(std::string("oi"));

    static_assert(std::is_same_v<decltype(42, void()), void>);
}