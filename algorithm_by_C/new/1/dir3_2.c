/**
 *    author:  shosei
 *    created: 26.01.2022 22:10:10
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define Num 10
#define Max 36
#define Min -20
#define Bias 1 - (Min)
int rank[Max + Bias + 1];

int main() {
  int a[] = {-3, 2, 3, -1, -2, -6, 2, -1, 1, 5};
  int i;

  rep(i, sizeof(a) / sizeof(a[0])) rank[a[i] + Bias]++;
  //一つ左側の要素の内容を加えていく
  rank[0] = 1;
  for (i = Min + Bias; i <= Max + Bias; i++) {
    rank[i] += rank[i - 1];
  }

  printf("  得点  順位\n");
  for (int i = 0; i <= Num; i++) {
    printf("%6d %6d\n", a[i], rank[a[i] + Bias - 1]);
  }

  return 0;
}