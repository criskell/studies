#include <iostream>
#include <future>

int task() {
	return 42;
}

int main() {
	std::future<int> result = std::async(std::launch::async, task);
	int value = result.get();
	std::cout << "Result: " << value << std::endl;
}
