/**
 *    author:  shosei
 *    created: 03.02.2022 22:26:30
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()

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

int get_right(Cube c1, int top, int front) {
  rep(i, 6) {
    rep(j, 4) {
      if (c1.f[0] == top && c1.f[1] == front) return c1.f[2];
      c1.roll_z();
    }
    if (i % 2 == 0)
      c1.roll_y();
    else
      c1.roll_x();
  }
  return -1;
}

int main() {
  Cube c;
  rep(i, 6) cin >> c.f[i];
  int q;
  cin >> q;

  int top, front;
  rep(i, q) {
    cin >> top >> front;
    cout << get_right(c, top, front) << endl;
  }
  return 0;
}