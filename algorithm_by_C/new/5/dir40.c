/**
 *    author:  shosei
 *    created: 17.02.2022 18:55:33
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
  char key[20];
  struct tfield *head, *p, *old1, *old2, *q;

  head = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    p->next = head;
    head = p;
  }
  p = talloc();
  p->next = head;
  head = p;

  rewind(stdin);
  //探索
  while (printf("key name: "), scanf("%s", key) != EOF) {
    p = head->next;
    old1 = old2 = head;
    while (p != NULL) {
      if (strcmp(key, p->name) == 0) {
        printf("%15s%15s\n", p->name, p->tel);
        if (p != head->next) {
          q = old1->next;  // qはtmpみたいな感じ
          old1->next = p;
          old2->next = p->next;
          p->next = q;
        }
        break;
      }
      old1 = old2;
      old2 = p;
      p = p->next;
    }
  }
  printf("\n");
  //出力
  p = head->next;
  while (p != NULL) {
    printf("%15s%15s\n", p->name, p->tel);
    p = p->next;
  }
  return 0;
}