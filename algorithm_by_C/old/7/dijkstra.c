/**
 *    author:  shosei
 *    created: 29.06.2021 23:08:42
 **/
#include <stdio.h>
#include <stdlib.h>

#define N 8  //ノードの数
#define M 9999

int a[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},  // 隣接行列
    {0, 0, 1, 7, 2, M, M, M, M}, {0, 1, 0, M, M, 2, 4, M, M},
    {0, 7, M, 0, M, M, 2, 3, M}, {0, 2, M, M, 0, M, M, 5, M},
    {0, M, 2, M, M, 0, 1, M, M}, {0, M, 4, 2, M, 1, 0, M, 6},
    {0, M, M, 3, 5, M, M, 0, 2}, {0, M, M, M, M, M, 6, 2, 0}};

int main() {
  int leng[N + 1],  //始点からノードまでの距離を管理する
      conf[N + 1],  //確定フラグ
      min,          //最小値
      p,            //最小値を与えるノード
      start,        //始点
      i, k,
      index[N + 1],  //前のノードへのポインタ
      tmp[N + 1],    //スタック
      sp = 0, count = 0;

  //初期化
  for (i = 1; i <= N; i++) {
    leng[i] = M;
    conf[i] = 0;
  }
  printf("START : ");
  scanf("%d", &start);

  //ダイクストラ法
  leng[start] = 0;
  index[start] = 0;  //始点は前のノードが無い
  while (count != N) {
    min = M;
    for (i = 1; i <= N; i++) {
      if (conf[i] == 0 && leng[i] < min) {
        p = i;
        min = leng[i];
      }
    }
    conf[p] = 1;
    count++;
    if (leng[p] == M) {
      printf("グラフが連結ではない\n");
      exit(1);
    }
    for (i = 1; i <= N; i++) {
      if (/*conf[i] == 0 　&& 無くても良い*/ (leng[p] + a[p][i]) < leng[i]) {
        leng[i] = leng[p] + a[p][i];
        index[i] = p;
      }
    }
  }
  for (i = 1; i <= N; i++) {
    p = i;
    sp = 0;
    while (index[p] != 0)  // 0は始点
    {
      tmp[sp++] = index[p];
      p = index[p];
    }
    printf("Distance: %d\nNode : %d\nRoute : ", leng[i], i);
    while (sp != 0) printf("%d --> ", tmp[--sp]);
    printf("%d\n\n", i);
  }
}
