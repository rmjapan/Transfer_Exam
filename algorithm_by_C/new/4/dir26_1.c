/**
 *    author:  shosei
 *    created: 07.02.2022 23:37:54
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

long fib(long n) {
  if (n == 1 || n == 2) return 1L;

  return fib(n - 1) + fib(n - 2);
}

int main() {
  for (int i = 1; i <= 20; i++) {
    printf("%3d: %ld\n", i, fib(i));
  }
  return 0;
}