#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **strings = malloc(sizeof(char*) * 2);
  char *msg1 = malloc(sizeof(char) * 8);
  char *msg2 = malloc(sizeof(char) * 8);

  int a = 12;
  int *p_a = &a;

  strcpy(msg1, "Hello");
  strcpy(msg2, "Message");

  strings[0] = msg1;
  strings[1] = msg2;

  printf("%s\n", strings[0]);
  printf("%s\n", strings[1]);

  // a
  printf("a pointer: %p", p_a);
  printf("a pointer value: %i", *p_a);

  return 0;
}

