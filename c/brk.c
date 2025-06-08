#include <unistd.h>
#include <stdio.h>

int main()
{
  void *heap_start = sbrk(0);
  printf("Heap starts at: %p\n", heap_start);

  sbrk(4096); // Allocate 4KiB of memory
  void *new_break = sbrk(0);
  printf("New heap end: %p\n", new_break);
}