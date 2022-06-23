/**
 *    author:  shosei
 *    created: 14.02.2022 21:01:15
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

typedef struct tfield {
  char name[20];
  char tel[20];
  struct tfield *next;
} TF;
TF *head;

TF *talloc();
void genlist();
void displist();
void del(char *);

int main() {
  char key[20];
  genlist();
  displist();

  while (printf("Key Name"), scanf("%s", key) != EOF) {
    del(key);
  }
  printf("\n");
  displist();
  return 0;
}

void del(char *key) {
  TF *p, *old;
  p = old = head;

  while (p != NULL) {
    if (strcmp(p->name, key) == 0) {
      if (p == head)
        head = p->next;
      else
        old->next = p->next;
      return;
    }
    old = p;
    p = p->next;
  }
  printf("キーデータが見つかりません\n");
}

TF *talloc() { return (TF *)malloc(sizeof(TF)); }

void genlist() {
  TF *p;

  head = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    p->next = head;
    head = p;
  }
  rewind(stdin);
}

void displist() {
  TF *p;

  p = head;
  while (p != NULL) {
    printf("%15s%15s\n", p->name, p->tel);
    p = p->next;
  }
}