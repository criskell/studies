#include <iostream>
#include <thread>

// Uma variável "thread_local" permite variáveis globais/estáticas que não são compartilhadas entre threads.
// Cada thread terá sua cópia.
thread_local int counter_in_thread = 0;
int counter_between_threads = 0;

void thread_function(int id) {
	++counter_in_thread;
	++counter_between_threads;

	std::cout << "[" << id << "]"
		<< " Counter in thread: " << counter_in_thread
		<< ", Counter between threads: " << counter_between_threads
		<< std::endl;
}

int main() {
	std::thread t1(thread_function, 1);
	std::thread t2(thread_function, 2);
	std::thread t3(thread_function, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}
