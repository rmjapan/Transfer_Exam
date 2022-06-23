/**
 *    author:  shosei
 *    created: 07.02.2022 23:48:18
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

long conbi(long n, long r) {
  if (r == n || r == 0) return 1L;

  return conbi(n - 1, r - 1) + conbi(n - 1, r);
}

int main() {
  for (int n = 0; n <= 5; n++) {
    for (int r = 0; r <= n; r++) {
      printf("%dC%d=%ld ", n, r, conbi(n, r));
    }
    printf("\n");
  }
  return 0;
}