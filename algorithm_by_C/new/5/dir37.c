/**
 *    author:  shosei
 *    created: 15.02.2022 22:41:26
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
  int value;
  struct tfield *right, *left;
} TF;

TF *talloc() { return (TF *)malloc(sizeof(TF)); }

int main() {
  TF *head, *p;

  head = talloc();  //ダミーノードの生成
  head->left = head->right = head;
  while (p = talloc(), scanf("%d", &p->value) != EOF) {
    p->right = head;
    p->left = head->left;
    head->left->right = p;
    head->left = p;
  }

  printf("\n 純方向リスト \n");
  p = head->right;
  while (p != head) {
    if (p != head->right) printf(" ");
    printf("%d", p->value);
    p = p->right;
  }

  printf("\n 逆方向リスト \n");
  p = head->left;
  while (p != head) {
    if (p != head->left) printf(" ");
    printf("%d", p->value);
    p = p->left;
  }
  printf("\n");
  return 0;
}