/**
 *    author:  shosei
 *    created: 03.02.2022 19:36:13
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

#define N 6

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int a[] = {80, 41, 35, 90, 40, 20};

  for (int i = 0; i < N - 1; i++) {
    for (int j = N - 1; j > i; j--) {
      if (a[j - 1] > a[j]) swap(&a[j - 1], &a[j]);
    }
  }
  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}