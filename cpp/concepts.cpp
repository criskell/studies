#include <print>

// Criamos um conceito.
template <typename T>
concept Incrementable = requires(T x) {
    // Expressão de restrição.
    // Usada para verificar se certas expressões são válidas com um tipo.
    x++;
    ++x;
};

// Cláusula de restrição.
// Usada para restringir tipos.
template <typename T>
    requires Incrementable<T>
void increment(T &x)
{
    ++x;
}

// Forma curta:
template <Incrementable T>
void increment_shorthand(T &x)
{
    ++x;
}

// A cláusula de restrição é da forma "requires X" onde X é uma expressão de restrição
// Uma expressão de restrição pode tomar a forma "requires (T x) { expr }"
template <typename T>
void print_if_has_size(const T &x)
    requires requires(T x) { x.size(); }
{
    std::println("{}", x.size());
}

// Como conceito:
template <typename T>
concept HasSize = requires(T x) {
    x.size();
};

template <HasSize T>
void print_size(T x)
{
    std::println("Size: {}", x.size());
}

template <auto x>
void check_if_has_size_method()
{
    if constexpr (requires { x.size(); })
    {
        std::println("tem o método size!");
    }
    else
    {
        std::println("não tem o método size!");
    }
}

int main()
{
    int x = 10;
    std::println("Valor de x: {}", x);

    increment(x);
    std::println("Valor de x: {}", x);

    increment_shorthand(x);
    std::println("Valor de x: {}", x);

    print_if_has_size(std::string("crissssssssssssssssssssssssssssss"));
    print_size(std::string("oix"));

    constexpr std::array numbers{1, 2, 3};
    constexpr int y = 42;

    check_if_has_size_method<numbers>();
    check_if_has_size_method<y>();
}