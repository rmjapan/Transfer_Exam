/**
 *    author:  shosei
 *    created: 10.02.2022 22:14:33
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
#define N 10

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void quick_sort(int a[], int left, int right) {
  int piv, i, j;
  if (left < right) {
    piv = a[(left + right) / 2];
    i = left;
    j = right;
    while (1) {
      while (piv > a[i]) i++;
      while (piv < a[j]) j--;
      if (i >= j) break;
      swap(&a[i], &a[j]);
    }

    quick_sort(a, left, i - 1);
    quick_sort(a, j + 1, right);
  }
}

int main() {
  static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};
  quick_sort(a, 0, N - 1);

  rep(i, N) {
    if (i != 0) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}