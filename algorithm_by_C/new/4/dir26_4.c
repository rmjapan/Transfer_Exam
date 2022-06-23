/**
 *    author:  shosei
 *    created: 08.02.2022 00:01:11
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

int gcd(int m, int n) { return (n ? gcd(n, m % n) : m); }
int main() {
  int a, b;
  printf("二つの整数:");
  scanf("%d %d", &a, &b);

  printf("%d", gcd(a, b));
  return 0;
}