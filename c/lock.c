#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

// necessita de root para rodar ou CAP_IPC_LOCK.
// pmap para inspecionar os mapeamentos de memória. sudo pmap -X $(pidof lock)
int main() {
  const size_t size = 1024 * 1024 * 1024;
  char *buffer = malloc(size);

  if (buffer == NULL) {
    perror("malloc");
    return 1;
  }

  // Assegura que mapeamos a memória.
  for (size_t i = 0; i < size; i++) {
    buffer[i] = 'A';
  }

  // Bloqueia a região de memória para swapping.
  if (mlock(buffer, size) != 0) {
    perror("mlock");
    return 1;
  }

  printf("Memória bloqueada em %p. Pressione enter para sair.\n", buffer);
  getchar();

  munlock(buffer, size);
  free(buffer);
  return 0;
}