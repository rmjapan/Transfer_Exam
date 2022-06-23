/**
 *    created by: shosei
 *    13.06.2022 19:57:22
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

int main() {
  int N, M;
  cin >> N >> M;
  graph G(N);
  vi dependant(N, 0);
  for (int i = 0; i < M; i++) {
    int f, s;
    cin >> f >> s;
    G[f].push_back(s);
    dependant[s]++;  //頂点sの入次数を増やす
  }

  queue<int> que;
  //依存数が0の課題の番号をすべて格納する．
  int num = 0;
  rep(i, N) if (dependant[i] == 0) {
    que.push(i);
    num++;
  }

  while (!que.empty()) {
    int T = que.front();
    que.pop();

    for (auto v : G[T]) {
      dependant[v]--;
      if (dependant[v] == 0) {
        que.push(v);
        num++;
      }
    }
  }

  if (num == N)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

