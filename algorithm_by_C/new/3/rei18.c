/**
 *    author:  shosei
 *    created: 03.02.2022 19:13:31
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
  int min = 99999, minpos;

  for (int i = 0; i <= N-2; i++) {
    min = a[i];
    minpos = i;
    for (int j = i+1; j < N; j++) {
      if (min > a[j]) {
        min = a[j];
        minpos = j;
      }
    }
    swap(&a[i], &a[minpos]);
  }

  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}