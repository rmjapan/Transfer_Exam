/**
 *    author:  shosei
 *    created: 03.02.2022 19:49:04
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

#define N 9
void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  int a[] = {3, 5, 6, 9, 2, 7, 8, 10, 4};
  int left, right, i, shift, t;

  left = 0;
  right = N - 1;
  while (left < right) {
    for (i = left; i < right; i++) {
      if (a[i] > a[i + 1]) {
        swap(&a[i], &a[i + 1]);
        shift = i;  //最後に入れ替えが起きた位置
      }
    }
    right = shift;

    for (i = right; i > left; i--) {
      if (a[i - 1] > a[i]) {
        swap(&a[i - 1], &a[i]);
        shift = i;
      }
    }
    left = shift;
  }

  rep(i, N) { printf("%d ", a[i]); }
  printf("\n");
  return 0;
}