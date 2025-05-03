#include <iostream>
#include <thread>
#include <mutex>

int global_variable = 0;
std::mutex global_mutex;

void thread_function(int id) {
	int local_variable = 0;
	++local_variable;

	global_mutex.lock();
	++global_variable;
	std::cout << "[THREAD " << id << "]"
		<< " Global variable: " << global_variable
		<< ", Local variable: " << local_variable
	       	<< std::endl;
	global_mutex.unlock();	
}

int main() {
	std::thread t1(thread_function, 1);
	std::thread t2(thread_function, 2);
	std::thread t3(thread_function, 3);

	t1.join();
	t2.join();
	t3.join();
}
