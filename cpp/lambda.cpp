#include <print>
#include <memory>
#include <functional>

std::function<void()> make_lambda_wrong()
{
  auto ptr = std::make_unique<int>(17);

  // errado:
  // return [ptr]()
  // - ptr não pode ser copiado. apenas movido.
  return [&ptr]()
  {
    std::println("Value: {}", *(ptr.get()));
  };
}

auto make_lambda()
{
  auto ptr = std::make_unique<int>(18);

  return [ptr = std::move(ptr)]()
  {
    std::println("Value: {}", *(ptr.get()));
  };
}

int main()
{
  auto f_wrong = make_lambda_wrong();
  f_wrong();

  auto f = make_lambda();
  f();
}