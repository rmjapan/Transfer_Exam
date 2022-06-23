/**
 *    created by: shosei
 *    13.06.2022 17:50:18
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

using Node = pair<int, int>;

//四方向への移動を表すベクトル
vi dxs = {1, 0, -1, 0};
vi dys = {0, 1, 0, -1};

int main() {
  int H, W, X0, Y0, X1, Y1;
  cin >> H >> W;
  cin >> X0 >> Y0 >> X1 >> Y1;
  vector<string> S(H);
  rep(i, H) cin >> S[i];

  //各マス(x, y)が何手目に探索されたか
  //-1は「まだ探索されていない」
  vii dist(H, vi(W, -1));

  queue<Node> que;

  dist[X0][Y0] = 0;
  que.push(Node(X0, Y0));

  while (!que.empty()) {
    auto x = que.front().first;
    auto y = que.front().second;
    que.pop();

    //マス(x, y)を中心とした4方向について調べる
    for (int direction = 0; direction < 4; ++direction) {
      int x2 = x + dxs[direction];
      int y2 = y + dys[direction];

      //マス(x2, y2)が画面が居もしくは黒マスである場合はスキップ
      if (x2 < 0 || x2 >= W || y2 < 0 || y2 >= W || S[x2][y2] == 'B') continue;

      //探索済みなら何もしない
      if (dist[x2][y2] != -1) continue;

      dist[x2][y2] = dist[x][y] + 1;
      que.push(Node(x2, y2));
    }
  }

  cout << dist[X1][Y1] << endl;

  return 0;
}