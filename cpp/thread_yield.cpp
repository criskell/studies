#include <iostream>
#include <thread>

void func() {
	for (int i = 0; i < 5; ++i) {
		std::cout << "Thread rodando...\n";
		std::this_thread::yield();
	}
}

int main() {
	std::thread t(func);

	for (int i = 0; i < 5; i++) {
		std::cout << "Main thread...\n";
		std::this_thread::yield();
	} 

	t.join();
}
