/**
 *    author:  shosei
 *    created: 02.02.2022 22:31:21
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

class Cube {
 public:
  int f[6];  //さいころ
  Cube() {}  //コンストラクタ.オブジェクトを作ったときに実行される
  void roll_z() { roll(1, 2, 4, 3); }
  void roll_y() { roll(0, 2, 5, 3); }      // to W インライン関数
  void roll_x() { roll(0, 1, 5, 4); }      // to N
  void roll(int i, int j, int k, int l) {  //巡回置換
    int t = f[i];
    f[i] = f[j];
    f[j] = f[k];
    f[k] = f[l];
    f[l] = t;
  }
  void move(char ch) {
    switch (ch) {
      case 'E':
        rep(i, 3) roll_y();  // Wを3回
        break;
      case 'W':
        roll_y();
        break;
      case 'N':
        roll_x();
        break;
      case 'S':
        rep(i, 3) roll_x();
        break;
      default:
        cout << "This command is undefined" << endl;
        exit(1);
    }
  }
};

bool is_samedice(Cube c1, Cube c2) {
  bool flag;
  rep(i, 6) {
    rep(j, 4) {
      flag = true;
      rep(i, 6) {
        if (c1.f[i] != c2.f[i]) flag = false;
      }
      if (flag) return true;
      c1.roll_z();
    }
    if (i % 2 == 0)
      c1.roll_y();
    else
      c1.roll_x();
  }
  return false;
}

int main() {
  int n;
  cin>>n;
  vector<Cube> d(n);

  //全てのダイスの入力
  rep(i,n){
    rep(j,6) cin>>d[i].f[j];
  }
  //一つでも同じものがあればNoで終了
  for(int i = 0; i<n; i++){
    for(int j = i+1; j<n; j++){
      if(is_samedice(d[i],d[j])){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}