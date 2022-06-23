/**
 *    author:  shosei
 *    created: 17.02.2022 21:11:22
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
#define TabSize 1000
#define ModSize 1000

int hash(char *);

struct tfield {
  char name[20];
  char tel[20];
  struct tfield *pointer;
} * dat[TabSize];

struct tfield *talloc() {
  return (struct tfield *)malloc(sizeof(struct tfield));
}

int main() {
  int n;
  char key[20];
  struct tfield *p;

  for (n = 0; n < TabSize; n++)  //ポインタテーブルの初期化
    dat[n] = NULL;

  printf("名前  電話番号\n");
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF) {
    n = hash(p->name);
    p->pointer = dat[n];
    dat[n] = p;
  }

  rewind(stdin);
  printf("Enter the data you want to search: ");
  while (scanf("%s", key) != EOF) {
    n = hash(key);
    p = dat[n];
    while (p->pointer != NULL && strcmp(p->name, key) != 0) p = p->pointer;
    if (p == NULL)
      printf("Not faund");
    else
      printf("%15s%15s", p->name, p->tel);
  }
  return 0;
}

int hash(char *s) {
  int n;
  n = strlen(s);
  return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) %
         ModSize;
}