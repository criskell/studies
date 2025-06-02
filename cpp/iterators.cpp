#include <print>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6};

  std::vector<int>::iterator it;

  // .begin() retorna um iterator para o primeiro elemento.
  // .end() retorna um iterator após o último elemento.
  // *it retorna o valor apontado.
  for (it = v.begin(); it != v.end(); ++it) {
    std::print("{} ", *it);
  }
}