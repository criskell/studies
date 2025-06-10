int nonConstexprFunction()
{
  return 1;
}

constexpr int constexprFunction()
{
  return 1;
}

// lambdas tem constexpr implicitamente se tiver os requisitos de uma função constexpr.
auto lambda = []
{
  return 1;
};

int main()
{
  // erro:
  // constexpr auto a = nonConstexprFunction();
  constexpr auto b = constexprFunction();
  constexpr auto c = lambda();
}