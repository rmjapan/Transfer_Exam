/**
 *    created by: shosei
 *    2022.05.25. 15:27:43
 **/
#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAX 10000

int dp[MAX + 1][MAX + 1];

int lcs(char *x, char *y) {
  int i, j;
  int m = strlen(x);  // row
  int n = strlen(y);  // column

  // init
  for (i = 0; i <= m; i++) dp[i][0] = 0;
  for (j = 0; j <= n; j++) dp[0][j] = 0;

  for (i = 1; i <= m; i++) {
    for (j = 1; j <= n; j++) {
      if (x[i - 1] == y[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}

int main() {
  int q;
  char x[MAX], y[MAX];
  scanf("%d", &q);

  for (int i = 0; i < q; i++) {
    scanf("%s", x);
    scanf("%s", y);
    printf("%d\n", lcs(x, y));
  }
  return 0;
}