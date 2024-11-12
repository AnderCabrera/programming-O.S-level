#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *next;
};

int main() {
  struct Node *head = malloc(sizeof(struct Node));

  head->value = 1;
  head->next = malloc(sizeof(struct Node));
  head->next->value = 2;

  printf("head direction: %p\n", head);
  printf("first node value: %i\n", head->value);

  printf("second head direction: %p\n", head->next);
  printf("second node value: %i\n", head->next->value);
}
