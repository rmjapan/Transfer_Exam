/**
 *    author:  shosei
 *    created: 14.02.2022 20:37:43
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct tfield {
  char name[20];
  char tel[20];
  struct tfield *next;
};

struct tfield *talloc() {
  return (struct tfield *)malloc(sizeof(struct tfield));
}

int main() {
  struct tfield *head, *p, *old;

  head = talloc();
  old = head;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    old->next = p;
    old = p;
  }
  old->next = NULL;

  p = head->next;
  while (p != NULL) {
    printf("%15s%15s\n", p->name, p->tel);
    p = p->next;
  }
  return 0;
}