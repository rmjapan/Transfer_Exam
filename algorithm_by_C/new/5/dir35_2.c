/**
 *    author:  shosei
 *    created: 15.02.2022 18:57:33
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
  struct tfield *head, *p, sentinel;

  char key[20];

  head = &sentinel;  //番兵へのポインタ
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    p->next = head;
    head = p;
  }

  rewind(stdin);
  //サーチ
  while (printf("key name "), scanf("%s", key) != EOF) {
    strcpy(sentinel.name, key);  //番兵にキーを入れる
    p = head;
    while (strcmp(p->name, key) != 0) p = p->next;
    if (p != &sentinel) {
      printf("%15s%15s\n", p->name, p->tel);
    } else {
      printf("Not faund\n");
    }
  }
  return 0;
}