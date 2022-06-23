/**
 *    author:  shosei
 *    created: 20.02.2022 00:18:47
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
#define M 1046527
#define L 12
#define ModSize 1000

struct dict {
  char str[L];
  struct dict *pointer;
} * dat[M];

struct dict *talloc() {
  return (struct dict *)malloc(sizeof(struct dict));
}

int hash(char *s) {
  int n;
  n = strlen(s);
  return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) %
         ModSize;
}

void insert(char *str) {
  int n;
  struct dict *p, *q;
  p = talloc();
  strcpy(p->str, str);
  n = hash(p->str);
  if (dat[n] == NULL) {
    dat[n] = p;
    p->pointer = NULL;
  } else {
    q = dat[n];
    while (q->pointer != NULL) q = q->pointer;
    q->pointer = q;
    p->pointer = NULL;
  }
}

int find(char *key) {
  struct dict *p;
  int n = hash(key);
  p = dat[n];
  while (p != NULL) {
    if (strcmp(p->str, key) == 0) return 1;
    p = p->pointer;
  }
  return 0;
}

int main() {
  int i, n;
  char str[L], com[9];

  for (i = 0; i < M; i++) dat[i] = NULL;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s %s", com, str);

    if (com[0] == 'i')
      insert(str);
    else if (find(str))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}