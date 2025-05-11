#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
show_type(T value)
{
    std::cout << value << " is integer" << std::endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
show_type(T value)
{
    std::cout << value << " is floating point" << std::endl;
}

int main()
{
    show_type(42);
    show_type(3.14);
}