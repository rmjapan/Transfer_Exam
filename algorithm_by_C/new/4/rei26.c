/**
 *    author:  shosei
 *    created: 07.02.2022 22:51:30
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

long kaijo(int n) {
  if (n == 0) return 1L;
  return n * kaijo(n - 1);
}

int main() {
  for (int i = 0; i < 13; i++) {
    printf("%ld\n", kaijo(i));
  }
  return 0;
}