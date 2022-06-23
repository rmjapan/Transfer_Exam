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

int descendants[10000];

//vの子孫の個数を数え，descendantsに格納していく
int des_num(int v, Graph &G) {
  //ベースケース
  if(G[v].empty()) return 0; //子が繋がっていないとき

  for (auto ch : G[v]) {
    descendants[v] += des_num(ch, G) + 1; //子供の子孫の数＋子供の数がvの子孫の数となる．
  }
  return descendants[v];
}

int main() {
  int N;
  cin >> N;
  Graph G(N);

  for(int i = 0; i<N; i++) descendants[i] = 0;
  //隣接リストの生成
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    G[p].push_back(i);
  }

  des_num(0, G);

  for(int i = 0; i<N; i++){
    cout<<descendants[i]<<endl;
  }
  return 0;
}