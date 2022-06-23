/**
 *    author:  shosei
 *    created: 28.02.2022 23:47:39
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
#define N 8  // 節点の数
#define M 9999

int a[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 隣接行列
    {0, 0, 1, 7, 2, M, M, M, M}, {0, 1, 0, M, M, 2, 4, M, M},
    {0, 7, M, 0, M, M, 2, 3, M}, {0, 2, M, M, 0, M, M, 5, M},
    {0, M, 2, M, M, 0, 1, M, M}, {0, M, 4, 2, M, 1, 0, M, 6},
    {0, M, M, 3, 5, M, M, 0, 2}, {0, M, M, M, M, M, 6, 2, 0}};

int main() {
  int j, k, p, start, min, leng[N + 1],
      v[N + 1];     //確定フラグ
  int prev[N + 1];  //前の節点へのポインタ

  printf("始点 ");
  scanf("%d", &start);
  for (k = 1; k <= N; k++) {  //初期化
    leng[k] = M;
    v[k] = 0;
  }
  leng[start] = 0;

  for (j = 1; j <= N; j++) {
    min = M;  //最小の接点を探すy
    for (k = 1; k <= N; k++) {
      if (v[k] == 0 && leng[k] < min) {  // 1周目はstartが最小
        p = k;
        min = leng[k];
      }
    }
    v[p] = 1;  //最小の点を確定する

    if (min == M) {
      printf("グラフは連結ではない\n");
      exit(1);
    }
    //ｐを経由してｋに至るまでの長さがそれまでの最短路より小さければ更新
    for (k = 1; k <= N; k++) {
      if ((leng[p] + a[p][k]) < leng[k]) {
        leng[k] = leng[p] + a[p][k];  // a[p][k]=Mはスルーされる
        prev[k] = p;                  // kの前はp
      }
    }
  }

  for (j = 1; j <= N; j++) {
    printf("%3d : %d", leng[j], j);  //始点から終端jまでの長さを出力
    p = j;
    while (prev[p] != 0) { //始点の前は０が入っている→つまり始点まで続ける
      printf(" <-- %d", prev[p]);
      p = prev[p];
    }
    printf("\n");
  }
  return 0;
}