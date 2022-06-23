/**
 *    author:  shosei
 *    created: 02.03.2022 03:01:01
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

#define N 4

int main() {
  int hojin[N + 1][N + 1];
  int i, j, k;

  k = 0;
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      k++;
      if ((i % 4 + j % 4) % 4 == 1 || i % 4 == j % 4) {
        hojin[i][j] = N * N - k + 1;
      } else {
        hojin[i][j] = k;
      }
    }
  }

  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      printf("%4d", hojin[i][j]);
    }
    printf("\n");
  }

  return 0;
}