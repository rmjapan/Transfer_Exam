/**
 *    author:  shosei
 *    created: 27.02.2022 00:13:43
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
    {0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0}};
int v[N + 1], s[N + 1];  // 訪問フラグ

void visit(int);

int main() {
  int i;
  for (i = 1; i <= N; i++) v[i] = 0;
  for (i = 1; i <= N; i++)
    if (v[i] == 0) visit(i);
  for (i = N; i >= 1; i--) printf("%d ", s[i]);
  printf("\n");
  return 0;
}

void visit(int i) {
  int j;
  static int sp = 1;  //スタックポインタ
  v[i] = 1;
  for (j = 1; j <= N; j++) {
    if (a[i][j] == 1 && v[j] == 0) visit(j);
    if (a[i][j] == 1 && v[j] == 1) {
      printf("%d と %dの付近にループがあります\n", i, j);
      exit(1);
    }
  }
  v[i] = 2;  //閉路の判定のため
  s[sp++] = i;
}