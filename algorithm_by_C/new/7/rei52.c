/**
 *    author:  shosei
 *    created: 26.02.2022 22:55:01
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

#define N 8  // 点の数

int a[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 隣接行列
    {0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 0}};
int v[N + 1];  // 訪問フラグ

int queue[100];
int head = 0, tail = 0;

int main() {
  int i, j, k;

  for (k = 1; k <= N; k++) {
    //初期化
    for (i = 1; i <= N; i++) v[i] = 0;
    head = tail = 0;

    queue[tail++] = k;
    v[k] = 1;
    while (head != tail) {
      i = queue[head++];
      for (j = 1; j <= N; j++) {
        if (a[i][j] == 1 && v[j] == 0) {
          printf("%d->%d ", i, j);
          queue[tail++] = j;
          v[j] = 1;
        }
      }
    }
    printf("\n");
  }
  return 0;
}