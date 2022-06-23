/**
 *    author:  shosei
 *    created: 08.02.2022 00:36:25
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

long fib(int n) {
  long a = 1, b = 1;
  if (n == 1 || n == 2) return 1L;
  long tmp;
  for (int i = 0; i < n - 2; i++) {
    tmp = b;
    b = a + b;
    a = tmp;
  }
  return b;
}

int main() {
  for (int i = 1; i <= 20; i++) {
    printf("%3d: %ld\n", i, fib(i));
  }
  return 0;
}