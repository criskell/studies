#include <iostream>
#include <future>

int task() {
	return 42;
}

int main() {
	std::future<int> result = std::async(std::launch::deferred, task);
	int value = result.get();
	std::cout << "Lazy result: " << value << std::endl;
}
