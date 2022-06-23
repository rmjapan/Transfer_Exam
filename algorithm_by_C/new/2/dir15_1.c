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

void swap(double *a, double *b) {
  double tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int select_piv_pos(double a[N][N + 1], int k, double *max) {
  int s;
  for (int j = k; j < N; j++) {  //絶対値が最大のピボットを選択
    if (fabs(a[j][k]) > *max) {
      *max = fabs(a[j][k]);
      s = j;
    }
  }
  return s;
}

int main() {
  double a[N][N + 1] = {
      {2.0, 3.0, 1.0, 4.0}, {4.0, 1.0, -3.0, -2.0}, {-1.0, 2.0, 2.0, 2.0}};

  double piv, d, max, dumy;
  int s;
  for (int k = 0; k < N; k++) {
    max = 0;
    s = k;
    s = select_piv_pos(a, k, &max);
    if (max == 0) {
      printf("解けない");
      exit(1);
    }
    for (int j = 0; j <= N; j++) {
      swap(&a[k][j], &a[s][j]);  //行の入れ替え
    }

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