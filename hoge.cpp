/**
 *    created by: shosei
 *    09.06.2022 21:32:30
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;

void dfs(int s, vii &chs){
  cout<<s<<" ";
  for(auto ch : chs[s]){
    dfs(ch, chs);
  }
}

int main(){
  int N;
  cin>>N;

  vii chs(N); //頂点vの子頂点
  for(int v = 1; v < N; v++){
    int p;
    cin>>p;

    chs[p].push_back(v);
  }

  dfs(0, chs);
  cout<<endl;
  return 0;
}