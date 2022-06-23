/**
 *    created by: shosei
 *    13.05.2022 22:47:56
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

struct Point {
  double x, y;
};

void koch(int n, Point a, Point b) {
  if (n == 0) return;
  Point s, t, u;
  double th = M_PI * 60 / 180;  //度からラジアンへ返還
  //それぞれの点の座標を求める
  s.x = (2.0 * a.x + b.x) / 3.0;
  s.y = (2.0 * a.y + b.y) / 3.0;
  t.x = (a.x + 2.0 * b.x) / 3.0;
  t.y = (a.y + 2.0 * b.y) / 3.0;

  u.x = cos(th) * (t.x - s.x) - sin(th) * (t.y - s.y) + s.x;
  u.y = sin(th) * (t.x - s.x) + cos(th) * (t.y - s.y) + s.y;

  //出力しながら再帰呼び出しs→u→tの順
  koch(n - 1, a, s);                  //区間(a,s)の座標を出力
  printf("%.8lf %.8lf\n", s.x, s.y);  // sの出力
  koch(n - 1, s, u);                  //区間(s, u)の座標を出力
  printf("%.8lf %.8lf\n", u.x, u.y);  // uの出力
  koch(n - 1, u, t);
  printf("%.8lf %.8lf\n", t.x, t.y);
  koch(n - 1, t, b);
}

int main() {
  int n;
  cin >> n;
  Point a, b;

  a.x = 0.0;
  a.y = 0.0;
  b.x = 100.0;
  b.y = 0.0;

  printf("%.8lf %.8lf\n", a.x, a.y);
  koch(n, a, b);  //区間(a, b)の座標を出力
  printf("%.8lf %.8lf\n", b.x, b.y);
  return 0;
}