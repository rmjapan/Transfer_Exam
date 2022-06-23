/**
 *    author:  shosei
 *    created: 05.02.2022 22:23:51
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

#define N 10
#define M 5
#define MAXEOF 1e9

int main() {
  int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40, MAXEOF}, b[] = {6, 11, 25, 33, 35, MAXEOF},
      c[M + N];

  int i, j, p;
  i = j = p = 0;
  while (i < N || j < M) {  // a[],b[]が終わりでない間
    if (a[i] <= b[j]) {
      c[p++] = a[i++];
    } else {
      c[p++] = b[j++];
    }
  }

  rep(i, M + N) { printf("%d ", c[i]); }
  printf("\n");
  return 0;
}