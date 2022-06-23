#include <algorithm>
#include <iostream>
using namespace std;

static const int N = 100;
static const int INF = (1 << 21);

int m[N + 1][N + 1];

void print_m(int n) {
  int i, j;

  for (i = 1; i <= n; i++) {
    for (j = 2; j <= n; j++) {
      printf("%7d ", m[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int n, p[N + 1];

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i - 1] >> p[i];
  }

  for (int i = 1; i <= n; i++) m[i][i] = 0;  //自分自身との積は考えない

  //メインの処理
  /*
  l : 対象とする行列の数
  対象とする行列の数lを増やしながら，その範囲を指定するiとjを決める．さらにそのうえで，
  iからjの範囲でkの位置を決めている．
  */
  print_m(n);
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INF;
      for (int k = i; k <= j - 1; k++) {
        m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
        print_m(n);
      }
    }
  }

  cout << m[1][n] << endl;  // M_1～M_nまでの最小の掛け算の回数
  return 0;
}