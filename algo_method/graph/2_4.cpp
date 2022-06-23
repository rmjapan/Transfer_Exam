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
int max_depth = -1;

void dfs(int v, Graph &G, int depth) {
  if(max_depth < depth) max_depth = depth; //木の高さの更新
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


    cout << max_depth << endl;

  return 0;
}