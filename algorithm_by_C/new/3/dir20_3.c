/**
 *    author:  shosei
 *    created: 04.02.2022 19:36:47
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

#define N 100
int randN() { return (int)N * (rand() / (RAND_MAX + 0.1)); }
void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int a[N + 1];
  for (int i = 1; i <= N; i++) a[i] = randN();

  int i, j, t;
  a[0] = -9999;
  for (i = 2; i <= N; i++) {
    t = a[i];
    for (j = i - 1; a[j] > t;
         j--)  // a[0]>tは成り立たないからここでループを抜ける
      a[j + 1] = a[j];
    a[j + 1] = t;
  }

  rep(i, N + 1) {
    if (i != 0) printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}