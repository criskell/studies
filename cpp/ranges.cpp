#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm> // Necessário para std::ranges::min_element

int main() 
{
    std::vector<int> nums = {1, 2, 3}; // Removido o '&' inválido
    int x = *std::ranges::min_element(nums); // Correto

    std::cout << x;
    return 0;
}

