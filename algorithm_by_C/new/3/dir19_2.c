/**
 *    author:  shosei
 *    created: 04.02.2022 18:35:52
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
  int a[N], i, j, k, gap, t;

  rep(i, N) a[i] = randN();

  for (gap = 1; gap < N / 3; gap = 3 * gap + 1)
    ;  // Nより小さい範囲で最大のgapを求める

  while (gap > 0) {
    for (i =gap; i < N; i = i++) {
      for (j = i - gap; j >= 0; j = j - gap) {
        if (a[j] > a[j + gap])
          swap(&a[j], &a[j + gap]);
        else
          break;
      }
    }
    gap /= 3;
  }

  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}