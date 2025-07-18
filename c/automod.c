#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

void a();
void b();
void c();

int main()
{
  int page_size = getpagesize();
  void *addr = c - ((long int)c % page_size);

  if (mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC))
  {
    perror("mprotect");
    return 1;
  }

  ((unsigned char *)c)[14] = 0xD4;

  c();

  return 0;
}

void a()
{
  puts("Função A!");
}

void b()
{
  puts("Função B!");
}

void c()
{
  a();
}