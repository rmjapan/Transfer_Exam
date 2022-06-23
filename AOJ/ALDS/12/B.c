/**
 *    created by: shosei
 *    2022.05.23. 18:46:24
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define MAX 10000
#define INFTY 1000000
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[MAX][MAX];
int color[MAX];
int d[MAX], p[MAX];
int n;

// sからそのほかの頂点までの最短経路長を求めてd[]に格納する
void dijkstra(int s) {
  int u, v, minv;
  // init
  for (int i = 0; i < n; i++) {
    color[i] = WHITE;
    d[i] = INFTY;
  }

  d[s] = 0;
  color[s] = GRAY;
  p[s] = -1;
  while (1) {
    //最小のuを決める
    minv = INFTY;
    for (int i = 0; i < n; i++) {
      if (color[i] != BLACK && minv > d[i]) {
        minv = d[i];
        u = i;
      }
    }

    //変更が起きなければ終わり
    if (minv == INFTY) break;
    color[u] = BLACK;

    // d[u]の値の更新を行う
    for (v = 0; v < n; v++) {
      if(color[v] != BLACK && G[u][v] != INFTY){
        if(d[v] > d[u] + G[u][v]){
          d[v] = d[u] + G[u][v];
          color[v] = GRAY;
          p[v] = u;
        }
      }
    }
  }
}

int main() {
  int u, k, v, c;
  scanf("%d", &n);

  // init matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      G[i][j] = INFTY;
    }
  }

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      scanf("%d %d", &v, &c);
      G[u][v] = c;
    }
  }

  dijkstra(0);  // 0から各頂点への最短経路長を求める

  for (int i = 0; i < n; i++) {
    printf("%d %d\n", i, d[i]);
  }
  return 0;
}