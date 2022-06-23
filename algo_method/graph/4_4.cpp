/**
 *    created by: shosei
 *    14.06.2022 21:55:47
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

int vis_num = 0;

void dfs(int v, vi &visited, graph &G) {
  vis_num++;
  // cout << v << " ";
  visited[v] = 1;

  for (auto w : G[v]) {
    if (!visited[w]) dfs(w, visited, G);
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  graph G(N);
  vi visited(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  rep(i, N) visited[i] = 0;

  // rep(i, N) sort(G[i].begin(), G[i].end());
  dfs(0, visited, G);
  cout << N - vis_num << endl;
  return 0;
}