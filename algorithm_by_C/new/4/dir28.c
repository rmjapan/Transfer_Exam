/**
 *    author:  shosei
 *    created: 08.02.2022 18:16:06
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

#define N 3
int p[N + 1];

void perm(int);
void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int i;

  for (i = 1; i <= N; i++) p[i] = i;
  perm(1);
  return 0;
}

void perm(int i) {
  int j;
  if (i < N) {
    for (j = i; j <= N; j++) {
      swap(&p[i], &p[j]);
      perm(i + 1);
      swap(&p[i], &p[j]);  //元に戻す
    }
  } else {
    for (j = 1; j <= N; j++) printf("%d", p[j]);  //順列の表示
    printf("\n");
  }
}