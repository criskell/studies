#include <stdio.h>

extern char symbol;
extern char symbol2;
extern char symbol3;

int main() { printf("olá mundo! %ld %p", &symbol2 - &symbol, &symbol3); }