/**
 *    author:  shosei
 *    created: 07.02.2022 23:52:51
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

#define N 4

double fn(double x, double a[], int i) {
  if (i == 0) return a[N];

  return fn(x, a, i - 1) * x + a[N - i];
}

int main() {
  double a[] = {1, 2, 3, 4, 5};  // 係数
  double x;

  printf("%f\n", fn(2, a, N));
  return 0;
}