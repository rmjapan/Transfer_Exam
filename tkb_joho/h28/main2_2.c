/**
 *    created by: shosei
 *    12.04.2022 21:02:51
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N 8
#define M 9999
//グラフははじアルと同じもの
int a[N + 1][N + 1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 7, 2, M, M, M, M},
                       {0, 1, 0, M, M, 2, 4, M, M}, {0, 7, M, 0, M, M, 2, 3, M},
                       {0, 2, M, M, 0, M, M, 5, M}, {0, M, 2, M, M, 0, 1, M, M},
                       {0, M, 4, 2, M, 1, 0, M, 6}, {0, M, M, 3, 5, M, M, 0, 2},
                       {0, M, M, M, M, M, 6, 2, 0}};

struct gnode {
  int det;       //確定フラグ
  int distance;  //距離管理
} node[N];

// s->gの最短経路長を返す
int dijkstra(int s, int g) {
  int i, j, min;
  //ノードの初期化
  for (i = 1; i <= N; i++) {
    node[i].det = 0;
    node[i].distance = M;
  }

  node[s].distance = 0;
  for (j = 1; j < N; j++) {
    node[s].det = 1;

    //ゴールが確定されたとき
    if (s == g) return node[g].distance;

    //確定した点の未確定な隣接要素までの距離を計算
    for (i = 1; i <= N; i++) {
      if (!node[i].det && a[s][i]) {
        if (node[i].distance > node[s].distance + a[s][i])
          node[i].distance = node[s].distance + a[s][i];
      }
    }

    //未確定の地点から最も小さい値を持つ地点を選び、その値を確定させる
    min = M;
    for (i = 1; i <= N; i++) {
      if (!node[i].det) {
        if (min > node[i].distance) {
          min = node[i].distance;
          s = i;
        }
      }
    }
  }
  return -1;  //経路が存在しないとき
}

int main() {
  int s = 1;
  printf("始点：%d\n", s);
  for (int i = 1; i <= N; i++) {
    printf("%d->%d : %d\n", s, i, dijkstra(s, i));
  }
  return 0;
}