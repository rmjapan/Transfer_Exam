/**
 *    author:  shosei
 *    created: 02.03.2022 02:32:45
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

#define N 3

int main() {
  int hojin[N + 1][N + 1];
  int i, j, k;

  j = (N + 1) / 2;
  i = 0;
  for (k = 1; k <= N * N; k++) {
    if ((k % N) == 1)
      i++;
    else {
      i--;
      j++;
    }
    if (i == 0) i += N;
    if (j > N) j -= N;
    hojin[i][j] = k;
  }
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= N; j++) {
      printf("%d ", hojin[i][j]);
    }
    printf("\n");
  }
  return 0;
}