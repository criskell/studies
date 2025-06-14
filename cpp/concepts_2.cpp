#include <iostream>

template <typename T>
concept Printable = requires(T value) {
  // "->" é uma trailing return constraint.
  { std::cout << value } -> std::same_as<std::ostream &>;
};

// auto: template parameter deduzido automaticamente.
void println(Printable auto const &value)
{
  std::cout << value << std::endl;
}

template <Printable T>
void println2(T const &value)
{
  std::cout << value << std::endl;
}

int main()
{
  println(42);
  println("hello world!");
  println2(42.42);
}