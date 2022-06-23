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
void link(char *);

int main() {
  char key[20];
  genlist();
  displist();

  while (printf("Key Name"), scanf("%s", key) != EOF) {
    link(key);
  }
  printf("\n");
  displist();
  return 0;
}

TF *talloc() { return (TF *)malloc(sizeof(TF)); }

void link(char *key) {
  TF *p, *n;

  n = talloc();
  printf("additional data:");
  scanf("%s %s", n->name, n->tel);

  p = head;  //ここからキーデータのサーチ
  while (p != NULL) {
    if (strcmp(key, p->name) == 0) {
      n->next = p->next;
      p->next = n;
      return;
    }
    p = p->next;
  }

  //キーが見つからなかった時の処理
  printf("%sが見つからないので先頭に追加します\n", key);
  n->next = head;
  head = n;
}

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