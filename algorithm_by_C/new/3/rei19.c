/**
 *    author:  shosei
 *    created: 04.02.2022 17:52:13
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

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int randN() { return (int)N * (rand() / (RAND_MAX + 0.1)); }

int main() {
  int a[N];
  int t;
  rep(i, N) { a[i] = randN(); }
  int j;
  for (int i = 1; i < N; i++) {
    t = a[i];
    for (j = i - 1; a[j] > t && j >= 0; j--) a[j + 1] = a[j];
    a[j + 1] = t;
  }

  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}