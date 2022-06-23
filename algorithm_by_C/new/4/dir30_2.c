/**
 *    author:  shosei
 *    created: 10.02.2022 19:52:30
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

#define MAZE_SIZE 9

int m[MAZE_SIZE][MAZE_SIZE] = {
    {2, 2, 2, 2, 2, 2, 2, 2, 2}, {2, 0, 0, 0, 0, 0, 0, 0, 2},
    {2, 0, 2, 2, 0, 2, 2, 0, 2}, {2, 0, 2, 0, 0, 2, 0, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0, 2}, {2, 0, 0, 0, 0, 0, 2, 0, 2},
    {2, 2, 0, 2, 2, 0, 2, 2, 2}, {2, 0, 0, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 2, 2, 2, 2, 2}};
int Si, Sj, Ei, Ej, flag;
int ri[100], rj[100], sp = 0;

int visit(int, int);

int main() {
  flag = 0;
  Si = 1;
  Sj = 1;
  Ei = 7;
  Ej = 7;

  printf("\n迷路の探索");
  if (visit(Si, Sj) == 0) {
    printf("出口は見つかりませんでした");
  }

  printf("\n");
  return 0;
}

int visit(int i, int j) {
  static int path = 1;
  m[i][j] = 1;
  ri[sp] = i;
  rj[sp] = j;
  sp++;                      //訪問位置をスタックに積む
  if (i == Ei && j == Ej) {  //出口に到達したとき
    printf("\npath=%d\n", path++);
    for (int k = 0; k < sp; k++) {
      printf("(%d,%d) ", ri[k], rj[k]);
    }
    flag = 1;
  }

  if (m[i][j + 1] == 0) visit(i, j + 1);
  if (m[i][j - 1] == 0) visit(i, j - 1);
  if (m[i + 1][j] == 0) visit(i + 1, j);
  if (m[i - 1][j] == 0) visit(i - 1, j);

  sp--;  //スタックから捨てる
  m[i][j] = 0;
  return flag;
}
