#include <print>

template <typename T, typename U>
struct PairTraits
{
  static void info()
  {
    std::println("Generic version.");
  }
};

// Partial Specialization
template <typename T>
struct PairTraits<T, int>
{
  static void info()
  {
    std::println("Specializing with U = int.");
  }
};

// Total specialization
template <>
struct PairTraits<float, int>
{
  static void info()
  {
    std::println("Specializing with T = int and U = int.");
  }
};

int main()
{
  PairTraits<float, double>::info();
  PairTraits<char, int>::info();
  PairTraits<float, int>::info();
  PairTraits<int, float>::info();
}