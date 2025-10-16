// Based on https://cstack.github.io/db_tutorial/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estado necessário para interação com o `getline`.
typedef struct {
  // Buffer alocado durante a leitura.
  char* buffer;

  // Tamanho do buffer alocado.
  size_t buffer_length;

  // O número de bytes lido.
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer() {
  InputBuffer* input_buffer = (InputBuffer*) malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;

  return input_buffer;
}

void print_prompt() {
  printf("db> ");
}

void read_input(InputBuffer* input_buffer) {
  // Quando passamos NULL como primeiro argumento para `getline`, ele faz a alocação da memória necessária para armazenar
  // a linha e faz o `buffer` apontar para ela.
  ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }

  input_buffer->input_length = bytes_read - 1; // Ignora o new line final.
  input_buffer->buffer[bytes_read - 1] = 0;
} 

void close_input_buffer(InputBuffer* input_buffer) {
  free(input_buffer->buffer);
  free(input_buffer);
}

int main() {
  InputBuffer* input_buffer = new_input_buffer();

  while (1) {
    print_prompt();
    read_input(input_buffer);

    if (strcmp(input_buffer->buffer, ".exit") == 0) {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command: '%s'.\n", input_buffer->buffer);
    }
  }
}