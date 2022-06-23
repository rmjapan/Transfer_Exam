/**
 *    author:  shosei
 *    created: 01.02.2022 17:23:13
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

int main() {
  double a[N][N + 1] = {
      {2.0, 3.0, 1.0, 4.0}, {4.0, 1.0, -3.0, -2.0}, {-1.0, 2.0, 2.0, 2.0}};

  double d;
  int i, j, k;
  //前進消去
  for (k = 0; k < N - 1; k++) {  //ピボットを0～n-2行まで動かす
    for (i = k + 1; i < N; i++) {
      d = a[i][k] / a[k][k];
      for (j = k; j <= N; j++) {
        a[i][j] = a[i][j] - a[k][j] * d;
      }
    }
  }
  //後退代入
  for (i = N - 1; i >= 0; i--) {
    d = a[i][N];
    for (j = i + 1; j < N; j++) d = d - a[i][j] * a[j][N];
    a[i][N] = d / a[i][i];
  }

  for (i = 0; i < N; i++) {
    printf("x%d = %lf\n", i + 1, a[i][N]);
  }
  return 0;
}