#include <print>
#include <vector>

std::vector<int> calculate_squares(int max)
{
  std::vector<int> result;

  for (int i = 0; i * i <= max; ++i)
  {
    // Constrói o objeto no final do container.
    result.emplace_back(i);
  }

  return result;
}

int main()
{
  auto squares{calculate_squares(103)};

  for (auto current : squares)
  {
    std::print("{} ", current);
  }

  return 0;
}