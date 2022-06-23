/**
 *    author:  shosei
 *    created: 08.02.2022 22:33:46
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  using P = pair<string, int>;
  int n, q;
  int time = 0;  //時刻を管理
  queue<P> queue;
  cin >> n >> q;

  string name;
  int t;
  rep(i, n) {
    cin >> name >> t;
    queue.push(make_pair(name, t));
  }

  while (!queue.empty()) {  
    P p = queue.front();
    queue.pop();
    if (p.second <= q) {
      time += p.second;
      cout << p.first << " " << time << endl;
    } else {
      time += q;
      p.second -= q;
      queue.push(p);
    }
  }
  return 0;
}