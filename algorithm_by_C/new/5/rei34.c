#include <stdio.h>
#include <stdlib.h>

typedef struct tfield {
  char name[20];
  char tel[20];
  struct tfield *next;
} TF;

TF *talloc() { return (TF *)malloc(sizeof(TF)); }
int main() {
  TF *head, *p;
  head = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    p->next = head;
    head = p;
  }

  p = head;
  while (p != NULL) {
    printf("%15s%15s\n", p->name, p->tel);
    p = p->next;
  }
}