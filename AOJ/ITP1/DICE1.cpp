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
  void move(char ch);
};

void Cube::move(char ch) {
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

int main() {
  Cube c;  //さいころオブジェクト
  string com;
  rep(i, 6) cin >> c.f[i];  //サイコロの面
  cin >> com;

  rep(i, com.size()) c.move(com[i]);

  cout << c.f[0] << endl;
  return 0;
}