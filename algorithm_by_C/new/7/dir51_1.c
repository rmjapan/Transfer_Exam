/**
 *    author:  shosei
 *    created: 26.02.2022 22:20:39
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
    {0, 0, 1, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1, 0}};
int v[N + 1];  // 訪問フラグ

void visit(int i) {
  v[i] = 1;
  for (int j = 1; j <= N; j++) {
    if (a[i][j] == 1 && v[j] == 0) {
      printf("%d to %d ", i, j);
      visit(j);
    }
  }
}

void clear() {
  for (int i = 0; i <= N; i++) {
    v[i] = 0;
  }
}

int main() {
  int i;
  for (i = 1; i <= N; i++) {
    clear();
    printf("%d: \n  ", i);
    visit(i);
    printf("\n");
  }
  printf("\n");
  return 0;
}
