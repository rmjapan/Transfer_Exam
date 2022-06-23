/**
 *    created by: shosei
 *    22.05.2022 18:30:51
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

static const int MAX = 100;
static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim() {
  int d[MAX], p[MAX], color[MAX];
  int u, v, minv;
  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while (1) {
    u = -1;
    minv = INFTY;
    for (int i = 0; i < n; i++) {
      if (color[i] != BLACK && d[i] < minv) {
        minv = d[i];
        u = i;
      }
    }

    if (u == -1) break;  //変更が起きなかったとき
    color[u] = BLACK;

    for (v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u][v] != INFTY) {
        if (M[u][v] < d[v]) {
          d[v] = M[u][v];
          p[v] = u;
          //color[v] = GRAY;
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) sum += M[p[i]][i];
  }
  return sum;
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int e;
      cin >> e;
      M[i][j] = (e == -1) ? INFTY : e;  //-1のときINFTYへ変換して格納
    }
  }

  cout << prim() << endl;
  return 0;
}