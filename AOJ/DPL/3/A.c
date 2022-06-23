/**
 *    created by: shosei
 *    03.06.2022 12:59:12
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define MAX 1400

int H, W;
// dp[i][j]:点(i, j)を右下の頂点とする正方形の一片の長さ
//長方形が存在しない場合は0とする
int TILE[MAX][MAX], dp[MAX + 1][MAX + 1];  // DPの外側は0で埋める

void print_dp() {
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int min3(int a, int b, int c) { return min(a, min(b, c)); }

int solve() {
  int max_edge = 0;
  int i, j;

  // init
  for (i = 0; i < H; i++) dp[i][0] = 0;
  for (j = 0; j < W; j++) dp[0][j] = 0;

  //print_dp();
  for (i = 1; i <= H; i++) {
    for (j = 1; j <= W; j++) {
      if (TILE[i - 1][j - 1] == 1) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = min3(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
        if (dp[i][j] > max_edge) max_edge = dp[i][j];
      }
      //print_dp();
    }
  }

  return max_edge*max_edge; //最大の正方形の面積を返す
}

int main() {
  scanf("%d %d", &H, &W);

  //タイルは0インデックス
  rep(i, H) rep(j, W) scanf("%d", &TILE[i][j]);

  printf("%d\n", solve());
}