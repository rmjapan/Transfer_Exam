/**
 *    author:  shosei
 *    created: 28.02.2022 21:43:03
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
#define Node 4   // 節点の数
#define Root 6   // 辺の数
#define Start 1  // 開始点

int a[Node + 1][Node + 1] = {{0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 0},
                             {0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 1},
                             {0, 1, 1, 0, 0}};
int success,
    v[Root + 1],  // 経路を入れるスタック
    n;            // 通過してない道の数

void visit(int);

int main() {
  success = 0;
  n = Root;
  visit(Start);
  if (success == 0) printf("解なし\n");
  return 0;
}

void visit(int i) {
  int j;
  v[n] = i;
  if (n == 0 && i == Start) {
    printf("解 %d:", ++success);
    for (i = 0; i <= Root; i++) printf("%d", v[i]);
    printf("\n");
  } else {
    for (j = 1; j <= Node; j++)
      if (a[i][j] != 0) {
        a[i][j]--;
        n--;
        visit(j);
        a[i][j]++;
        n++;
      }
  }
}