#include <print>
#include <vector>
#include <cmath>

struct Inefficient
{
    char a;
    int b;
    char c[3];
};

struct Efficient
{
    int b;
    char a;
    char c[3];
};

int main()
{
    std::println("Inefficient size: {}", sizeof(Inefficient));
    std::println("Efficient size: {}", sizeof(Efficient));

    const std::vector<Inefficient> inefficientVector(100'000'000);
    const std::vector<Efficient> efficientVector(100'000'000);

    const double inefficientMemoryUsage = sizeof(Inefficient) * inefficientVector.size() / (1024.0 * 1024.0);
    const double efficientMemoryUsage = sizeof(Efficient) * efficientVector.size() / (1024.0 * 1024.0);

    std::println("Memory usage of inefficient vector: {:.2f} MB", inefficientMemoryUsage);
    std::println("Memory usage of efficient vector: {:.2f} MB", efficientMemoryUsage);

    const double difference = abs(inefficientMemoryUsage - efficientMemoryUsage);

    std::println("Difference: {:.2f} MB", difference);
}