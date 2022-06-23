/**
 *    author:  shosei
 *    created: 11.04.2022 23:25:17
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5

int a[N][N] = {{0, 1, 1, 0, 0},
               {1, 0, 0, 1, 0},
               {0, 0, 0, 1, 0},
               {0, 0, 0, 0, 0},
               {0, 0, 0, 1, 0}};

int visited[N];

int maxranked() {
  int i, j, rank, max = 0, node = -1;
  for (i = 0; i < N; i++) {
    rank = 0;
    for (j = 0; j < N; j++) {
      if (a[j][i]) rank++;
    }
    if (rank > max) {
      max = rank;
      node = i;
    }
  }
  return node;
}

//頂点sから頂点gまで到達可能なら１，そうでなければ０を返す
int is_reachable1(int s, int g) {
  int i;
  if (s == g) return 1;
  if (visited[s]) return 0;  //既に訪れていたら０

  visited[s] = 1;
  for (i = 0; i < N; i++) {
    if (a[s][i] && is_reachable1(i, g)) return 1;
  }
  return 0;
}

// visitedの初期化をするだけ，本体はis_reachable1
int is_reachable(int s, int g) {
  int i;
  for (i = 0; i < N; i++) {
    visited[i] = 0;
  }
  return is_reachable1(s, g);
}

int dijkstra(int s, int g) {
  struct node {
    int found;  //１の時確定状態，それ以外０
    int distance;  //ノードsからの距離，found=1のときここに最短距離が入る
  } node[N];

  int i, j, min;
  for (i = 0; i < N; i++) {  // init
    node[i].found = 0;
    node[i].distance = N;
  }

  node[s].distance = 0;
  for (j = 1; j < N; j++) {
    // sを確定(sは確定した点の隣接ノードのうち，s_0からの距離が最短となるようなノード)
    //はじアルを参照しながらやるとイメージ掴みやすい
    node[s].found = 1;

    if (s == g) return node[s].distance;

    // sの隣接ノード(未確定)に対し，s_0からの距離を計算
    // 元より小さいモノは更新する．
    for (i = 0; i < N; i++) {
      if (!node[i].found && a[s][i]) {
        if (node[i].distance > (node[s].distance + 1))
          node[i].distance = node[s].distance + 1;
      }
    }

    min = N;  //最小値を求めるための変数
    for (i = 0; i < N; i++) {
      if (!node[i].found)
        if (node[i].distance < min) {
          min = node[i].distance;
          s = i;
        }
    }
  }
  return -1;
}

int main() {
  int i, j;
  int s = 0, g = 1;
  // rankチェック用
  //  printf("node = %d\n", maxranked());

  // is_reachable1チェック用
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     if (i != j && is_reachable(i, j)) printf("%d->%d\n", i, j);
  //   }
  // }

  //ダイクストラ
  // printf("Mindist(%d->%d) = %d\n", s, g, dijkstra(s, g));

  for (int i = 0; i < N; i++) {
    printf("Node : %d\n", i);
    for (int j = 0; j < N; j++) {
      printf("Mindist(%d->%d)=%d\n", i, j, dijkstra(i, j));
    }
    printf("\n");
  }

  return 0;
}