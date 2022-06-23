/**
 *    created by: shosei
 *    21.04.2022 22:31:41
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N 1000
#define NO_PRIME -1

int main() {
  int i, j, min;
  int Prime[N + 1];  //-1のとき素数ではない
  // init
  for (i = 2; i <= N; i++) {
    Prime[i] = i;
  }

  int j_next = 2;
  for (i = 0; i <= sqrt(N); i++) {
    //ふるいの中から最小値を探す
    min = N;
    for (j = j_next; j <= N; j++) {
      if (Prime[j] != NO_PRIME) {
        min = Prime[j];
        j_next = j + 1;
        break;
      }
    }
    // minの倍数をふるいから外す
    j = 2;
    while (min * j <= N) {
      Prime[min * j] = NO_PRIME;
      j++;
    }
  }

  for (i = 2; i <= N; i++) {
    if (Prime[i] != NO_PRIME) printf("%d ", Prime[i]);
  }

  return 0;
}