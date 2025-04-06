#include <iostream>
#include <cstring>
#include <cstdlib>

int main() {
	unsigned char* p = (unsigned char*) malloc(4 * sizeof(unsigned char));
	memset(p, 0, 4);
	strcpy((char*) p, "abcdabcd");
	std::cout << p;
	free(p);
	std::cout << p;
	return 0;
}
