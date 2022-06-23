/**
 *    created by: shosei
 *    10.06.2022 15:59:41
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using Graph = vii;

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N);

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;

    G[A].push_back(B);
    G[B].push_back(A);
  }

  //各頂点が何手目に探索されたか
  //-1:まだ訪れていない
  vi dist(N, -1);

  // k手目に探索された頂点集合を格納
  vii nodes(N);

  dist[0] = 0;
  nodes[0] = {0};

  //k手目の探索をする
  for(int k = 1; k<N; k++){
    //k-1番目に格納された各頂点vに対して
    for(auto v : nodes[k-1]){
      //頂点vの隣接頂点に対して
      for(auto next_v : G[v]){
        //探索済みなら何もしない
        if(dist[next_v] != -1) continue;

        dist[next_v] = k;
        nodes[k].push_back(next_v);
      }
    }
  }

  for(int k = 0; k<N; k++){
    sort(nodes[k].begin(), nodes[k].end());

    for(auto v : nodes[k])
      cout<<v<<" ";
    cout<<endl;
  }

  return 0;
}