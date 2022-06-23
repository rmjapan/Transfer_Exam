/**
 *    created by: shosei
 *    13.06.2022 16:52:21
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

int d[10001];
int visited[10001];  // 0:未訪問, 1:訪問

void BFS(graph &G) {
  int dist;
  queue<int> que;

  d[0] = 0;
  visited[0] = 1;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    dist = d[v];  //現在のレベル

    //未訪問の子をキューに入れる
    for (auto w : G[v]) {
      if (!visited[w]) {
        que.push(w);
        visited[w] = 1;
        d[w] = dist + 1;
      }
    }
  }
}

void print_d(int N) {
  for (int i = 1; i < N; i++) {
    cout << d[i] << " ";
  }
  cout<<endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  graph G(N);

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  BFS(G);
  int maxv = d[0];
  for (int i = 1; i < N; i++) {
    if (maxv < d[i]) maxv = d[i];
  }
  //print_d(N);
  cout << maxv << endl;

  return 0;
}