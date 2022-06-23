/**
*    created by: shosei
*    10.06.2022 12:38:32
流れ
1. 隣接リストを生成
2. dfsをして最大の深さを求める
**/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;

using Graph = vii;
int Depth[10000];

void dfs(int v, Graph &G, int depth) {
  Depth[v] = depth; //現在地点vの深さを記録
  for (auto ch : G[v]) {
    dfs(ch, G, depth + 1);
  }
}

int main() {
  int N;
  cin >> N;
  Graph G(N);

  //隣接リストの生成
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
  }

  int depth = 0;
  dfs(0, G, 0);

  for (int i = 0; i < N; i++) {
    cout << Depth[i] << endl;
  }
  return 0;
}