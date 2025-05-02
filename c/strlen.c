#include <stdio.h>

int my_strlen(char* str)
{
    int length = 0;

    while (*str != 0) {
    	length++;
	str++;
    }
    
    return length;
}

int main() {
    printf("%d", my_strlen("Hello, world!"));

    return 0;
}
