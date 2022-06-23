/**
 *    author:  shosei
 *    created: 31.01.2022 18:45:38
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

  double piv, d;  //ピボット
  for (int k = 0; k < N; k++) {
    piv = a[k][k];
    for (int j = k; j < N + 1; j++)
      a[k][j] = a[k][j] / piv;  //ピボットで第k列を割る
    for (int i = 0; i < N; i++) {
      if (i != k) {
        d = a[i][k];  //行ベクトルの先頭になる（最初に０以外になる）数
        for (int j = k; j <= N; j++) a[i][j] = a[i][j] - a[k][j] * d;
      }
    }
  }

  for (int k = 0; k < N; k++) printf("x%d=%f\n", k + 1, a[k][N]);
  return 0;
}