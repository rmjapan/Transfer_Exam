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

  gap = N / 2;  //ギャップの初期値
  while (gap > 0) {
    for (k = 0; k < gap; k++) { //ここでずらしていく
      for (i = k + gap; i < N; i = i + gap) {
        for (j = i - gap; j >= k; j = j - gap) {
          if (a[j] > a[j + gap])
            swap(&a[j], &a[j + gap]);
          else
            break;
        }
      }
    }
    gap /= 2;
  }

  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}