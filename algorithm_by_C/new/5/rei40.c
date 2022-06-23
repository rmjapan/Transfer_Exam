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
  struct tfield *head, *p, *old;

  head = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    p->next = head;
    head = p;
  }
  rewind(stdin);
  //探索
  while (printf("key name: "), scanf("%s", key) != EOF) {
    p = old = head;
    while (p != NULL) {
      if (strcmp(key, p->name) == 0) {
        printf("%15s%15s\n", p->name, p->tel);
        if (p != head) {
          old->next = p->next;  //先頭に移す。削除⇒移動
          p->next = head;
          head = p;
        }
        break;
      }
      old = p;
      p = p->next;
    }
  }
  printf("\n");
  //出力
  p = head;
  while (p != NULL) {
    printf("%15s%15s\n", p->name, p->tel);
    p = p->next;
  }
  return 0;
}