#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<int>> matrix = {
  {1, 2, 3},
  {4, 5, 6},
  {},
  {7, 8, 9},
};

int main() 
{
  for (auto outer_it = matrix.begin(); outer_it != matrix.end(); ++outer_it) {
   if (!outer_it->empty()) {
    // continua se o iterator não está vazio...
    
    for (auto inner_it = outer_it->begin(); inner_it != outer_it->end(); ++inner_it) {
      std::cout << *inner_it << " ";
    }
    
    std::cout << std::endl;
   }
  }  
  
  return 0;
}