/**
*    author:  shosei
*    created: 27.02.2022 01:36:15
**/
#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vii = vector<vi>;

#define MAX 100000
typedef long long ll;

int n,k;
ll T[MAX]; //にもつ

//最大積載量Pのk台のトラックで何個の荷物を積めるか？
int check(ll P){
  int i = 0;
  for(int j = 0; j<k;j++){
    ll s = 0;
    while(s + T[i]<=P){
      s += T[i];
      i++;
      if(i == n) return n;
    }
  }
  return i;
}

int solve(){
  ll left = 0;
  ll right = 100000*10000; //荷物の個数×1個当たりの最大重量
  ll mid;
  while(right - left > 1){
    mid = (left + right)/2;
    int v = check(mid); //mid == Pを決めて何個積めるかチェック
    if(v==n) right = mid;
    else left = mid;
  }
  return right;
}

int main()
{
  cin>>n>>k;
  for(int i = 0; i<n; i++) cin>>T[i];
  ll ans = solve();
  cout<<ans<<endl;
  return 0;
}