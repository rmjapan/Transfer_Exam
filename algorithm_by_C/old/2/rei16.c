/**
 *    author:  shosei
 *    created: 01.02.2022 19:05:59
 **/

#include <math.h>
#include <stdio.h>

#define N1 4  //行数
#define N2 6  //列数
#define N3 2  //変数の数

int main() {
  double a[N1][N2] = {{1.0, 2.0, 1.0, 0.0, 0.0, 14.0},
                      {1.0, 1.0, 0.0, 1.0, 0.0, 8.0},
                      {3.0, 1.0, 0.0, 0.0, 1.0, 18.0},
                      {-2.0, -3.0, 0.0, 0.0, 0.0, 0.0}};
  int j, k, x, y, flag;
  double min, p, d;

  while (1) {
    min = 9999;
    for (k = 0; k < N2 - 1; k++) {  //列選択
      if (min > a[N1 - 1][k]) {
        min = a[N1 - 1][k];
        y = k;
      }
    }

    if (min >= 0) break;

    min = 9999;
    for (j = 0; j < N1 - 1; j++) {  //行選択
      p = a[j][N2-1]/a[j][y];
      if (a[j][y] > 0 && p<min) {
        min = p;
        x = j;
      }
    }

    p = a[x][y];
    for (k = 0; k < N2; k++) {  //ピボットのある行をピボットで割る
      a[x][k] = a[x][k] / p;
    }
    for (k = 0; k < N1; k++) {
      if (k != x) {
        d = a[k][y];
        for (j = 0; j < N2; j++) {
          a[k][j] = a[k][j] - a[x][j] * d;
        }
      }
    }
  }

  for (k = 0; k < N3; k++) {
    flag = -1;
    for (j = 0; j < N1; j++) {
      if (a[j][k] == 1)  // 1の要素を探す
        flag = j;
    }
    if (flag != -1)
      printf("x%d = %f\n", k, a[flag][N2 - 1]);
    else
      printf("x%d = %f\n", k, 0.0);
  }
  printf("z=%f\n", a[N1 - 1][N2 - 1]);
  return 0;
}