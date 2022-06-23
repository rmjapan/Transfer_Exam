/**
 *    author:  shosei
 *    created: 02.02.2022 18:36:57
 **/
#include <math.h>
#include <stdio.h>

#define N 7
#define M 5

double ipow(double p, int n) {
  int k;
  double s = 1;
  for (k = 1; k <= n; k++) {
    s = s * p;
  }
  return s;
}

int main() {
  double x[] = {-3, -2, -1, 0, 1, 2, 3}, y[] = {5, -2, -3, -1, 1, 4, 5},
         a[M + 1][M + 2], s[2 * M + 1], t[M + 1];

  /*
  1.sを求める
  2.tを求める
  3.はき出しでaを求める
  3.5. a[][]にs[],t[]の値を入れる
  4.補間多項式でyを計算
  */
  int i, j, k;
  double p, d, px;

  for (i = 0; i <= 2 * M; i++) s[i] = 0;
  for (i = 0; i <= M; i++) {
    t[i] = 0;
  }

  // 1
  for (i = 0; i <= 2 * M; i++) {
    for (j = 0; j < N; j++) s[i] += ipow(x[j], i);
  }

  // 2
  for (i = 0; i <= M; i++) {
    for (j = 0; j < N; j++) {
      t[i] += y[j] * pow(x[j], i);
    }
  }
  // 3.5
  for (i = 0; i < M + 1; i++) {
    for (j = 0; j < M + 1; j++) {
      a[i][j] = s[j + i];
    }
    a[i][M + 1] = t[i];
  }

  for (k = 0; k <= M; k++) {
    p = a[k][k];
    for (j = 0; j <= M + 1; j++)  //ピボットで割る
      a[k][j] = a[k][j] / p;

    for (i = 0; i < M + 1; i++) {
      if (i != k) {
        d = a[i][k];
        for (j = 0; j < M + 2; j++) {
          a[i][j] = a[i][j] - a[k][j] * d;
        }
      }
    }
  }

  printf("     x      y\n");
  for (px = -3; px <= 3; px = px + 0.5) {
    p = 0;
    for (k = 0; k <= M; k++) p = p + a[k][M + 1] * ipow(px, k);
    printf("%5.1f%5.1f\n", px, p);
  }
  return 0;
}