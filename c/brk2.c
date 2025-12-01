#include <unistd.h>
#include <stdio.h>

int main() {
	// Passa 0 e eu consigo o break atual do programa
	void *initial_break = sbrk(0);
	printf("Initial break: %p\n", initial_break);

	// Aloca 16 bytes
	sbrk(16);

	void *new_break = sbrk(0);
	printf("New break: %p\n", new_break);

	return 0;
}
