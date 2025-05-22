#include <print>
#include <string>

void identify_value_category(const std::string &s)
{
    std::println("l-value");
}

void identify_value_category(const std::string &&s)
{
    std::println("r-value");
}

template <typename T>
// Aqui "T&&" é uma forwarding reference que se adapta ao tipo original do argumento.
void perfect_forwarding_identify_value_category(T &&value)
{
    // std::forward garante que caso o argumento original for r-value
    // ele continua assim ao ser passado para identify_value_category.
    identify_value_category(std::forward<T>(value));
}

template <typename T>
void generic_identify_value_category(T &value)
{
    std::println("generic_identify_value_category: l-value");
}

template <typename T>
void generic_identify_value_category(T &&value)
{
    std::println("generic_identify_value_category: r-value");
}

int main()
{
    std::string name = "criskell";

    identify_value_category(name);

    // Estamos passando objetos "temporários" daqui para baixo.
    identify_value_category(std::string("ana"));

    // std::move converte um l-value em r-value.
    identify_value_category(std::move(name));

    perfect_forwarding_identify_value_category(std::string("teste"));

    std::string name2 = std::string("carolina");

    generic_identify_value_category(name2);
    generic_identify_value_category(std::string("oi"));
    generic_identify_value_category(std::move(name2));

    generic_identify_value_category(10);
    generic_identify_value_category(50);
    generic_identify_value_category(std::move(10));
}