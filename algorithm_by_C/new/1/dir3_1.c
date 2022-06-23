/**
 *    author:  shosei
 *    created: 24.01.2022 23:50:04
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define NUM 10
int juni[102];
int main() {
  int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
  juni[101] = 1;
  rep(i, NUM) juni[a[i]]++;

  //一つ右の要素を加えていく
  for (int i = 100; i >= 0; i--) {
    juni[i] += juni[i + 1];
  }

  printf("  得点  順位\n");
  rep(i, NUM) { printf("%6d%6d\n", a[i], juni[a[i] + 1]); }

  return 0;
}