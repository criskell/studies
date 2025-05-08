#include <iostream>
#include <vector>
#include <utility>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2;

    v2 = std::move(v1);

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
}