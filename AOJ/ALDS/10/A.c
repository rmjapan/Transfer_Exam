/**
 *    created by: shosei
 *    2022.05.23. 20:51:06
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int fibo(int n) {
  int a[45];
  a[0] = a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[n];
}

//メモ化再帰
int F[45];
int fibo2(int n) {
  if (n == 0 || n == 1) return F[n] = 1;
  if (F[n] != -1) return F[n];

  return F[n] = fibo2(n - 1) + fibo2(n - 2);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <=n; i++) F[i] = -1;
  printf("%d\n", fibo2(n));
  return 0;
}