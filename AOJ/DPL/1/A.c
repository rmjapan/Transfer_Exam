/**
 *    created by: shosei
 *    2022.05.26. 20:50:45
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a) > (b)) ? (b) : (a)

#define M 20
#define N 50000
#define INF (1 << 20)

int main() {
  int n, m;
  int C[M + 1];
  int T[N + 1];
  scanf("%d %d", &n, &m);

  // init
  for (int i = 1; i <= m; i++) scanf("%d", &C[i]);

  for (int i = 1; i <= n; i++) T[i] = INF;

  for (int i = 1; i <= m; i++) {
    for (int j = C[i]; j <= n; j++) {
      T[j] = min(T[j], T[j-C[i]] + 1);
    }
  }

  for(int i = 0; i<n; i++){}
  printf("%d\n", T[n]);
  return 0;
}