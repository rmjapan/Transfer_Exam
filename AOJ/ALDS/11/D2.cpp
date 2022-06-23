/**
*    created by: shosei
*    22.05.2022 15:55:42

1. 入力から隣接リストの生成(隣接行列ではTLE不可避)
2. 各ノードを連結要素で分けたグループに割り振る
3. 入力されたノードのペア(s, t)に対して同じグループに属しているかを調べる
**/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
static const int MAX = 100000;
static const int NIL = -1;  //どのグループにも属していない状態

vector<vector<int>> G(MAX);
vector<int> group(MAX);  // group[i]:ノードiが属するグループ
int id = 0;              //グループid

// iにつながっているノードに対して深さ優先で探索し，グループを割り振る
void dfs(int i, int id) {
  int v;  // iに隣接したノード
  for (int j = 0; j < G[i].size(); j++) {
    v = G[i][j];
    if (group[v] == NIL) {  // vがまだグループ番号が振られていないとき
      group[v] = id;  // vをグループidに入れる
      dfs(v, id);
    }
  }
}

void Allocate_to_group(int n) {
  for (int i = 0; i < n; i++)  // init
    group[i] = NIL;
  for (int i = 0; i < n; i++) {
    if (group[i] == NIL) {
      group[i] = id;  // iに色を割り振りDFS
      dfs(i, id++);
    }
  }
}

int main() {
  int n, m;
  int s, t, q;
  cin >> n >> m;

  //隣接リストの生成
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  //ノードをグループに割り振る
  Allocate_to_group(n);

  //メイン処理
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (group[s] == group[t])
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
  return 0;
}