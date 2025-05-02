#include <iostream>
#include <thread>
#include <future>

void task(std::promise<int> prom) {
	prom.set_value(52);
}

int main() {
	// Promises seria um canal de comunicação.
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();

	// Não é permitido fazer cópias de promises.
	// É necessário realizar um move.
	std::thread t(task, std::move(prom));

	int value = fut.get();
	std::cout << "Value: " << value << "\n";

	// Espera a thread terminar.
	// Mesmo depois do set_value na promise, a thread pode continuar.
	t.join();
}
