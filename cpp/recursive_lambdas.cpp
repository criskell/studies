#include <functional>
#include <print>

int main()
{
  std::function<int(int)> factorial;

  factorial = [&](int n)
  {
    return n <= 1 ? 1 : factorial(n - 1) * n;
  };

  std::println("{}", factorial(3));

  auto factorial2 = [](this auto self, unsigned int n) -> unsigned int
  {
    return 1 >= n ? 1 : self(n - 1) * n;
  };

  std::println("{}", factorial2(20));
}