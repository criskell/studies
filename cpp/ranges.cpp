#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() 
{
    namespace ranges = std::ranges;

    std::vector<int> nums = {1, 2, 3};
    int x = *ranges::min_element(nums);

    std::cout << x;
    return 0;
}

