/**
 *    created by: shosei
 *    01.06.2022 18:25:50
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N_MAX 100
#define W_MAX 10000

struct Item {
  int v;
  int w;
};

struct Item item[N_MAX + 1];
int dp[N_MAX + 1][W_MAX + 1];

void print(int N, int W) {
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= W; j++) {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  int N, W;
  cin >> N >> W;

  for (int i = 1; i <= N; i++) {
    scanf("%d %d", &item[i].v, &item[i].w);
  }

  for (int i = 0; i <= N; i++) dp[i][0] = 0;
  for (int j = 0; j <= W; j++) dp[0][j] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      if (j - item[i].w >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i-1][j - item[i].w] + item[i].v);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
      //print(N, W);
    }
  }
  cout << dp[N][W] << endl;
}