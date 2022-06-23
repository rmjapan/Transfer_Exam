/**
 *    author:  shosei
 *    created: 15.02.2022 21:44:23
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
  // char name[20];
  // char tel[20];
  int value;
  struct tfield *right, *left;
} TF;

TF *talloc() { return (TF *)malloc(sizeof(TF)); }

int main() {
  TF *head, *tail, *p;
  tail = NULL;
  while (p = talloc(), scanf("%d", &p->value) != EOF) {
    p->left = tail;  // p->prevでtailを指す
    tail = p;        // tailでpを指す
  }

  //順方向にリストを繋ぐ
  p = tail;
  head = NULL;
  while (p != NULL) {
    p->right = head;
    head = p;
    p = p->left;
  }

  printf("\n 純方向リスト \n");
  p = head;  //リストの順表示
  while (p != NULL) {
    if (p != head) printf(" ");
    printf("%d", p->value);
    p = p->right;
  }
  printf("\n");

  printf("\n 逆方向リスト \n");
  p = tail;
  while (p != NULL) {
    if (p != tail) printf(" ");
    printf("%d", p->value);
    p = p->left;
  }
  printf("\n");

  return 0;
}