/**
 *    author:  shosei
 *    created: 17.12.2021 23:41:10
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
//解法２
int combi(int n, int r)
{
  if (r == n || r == 0)
    return 1;
  else
    return combi(n - 1, r) + combi(n - 1, r - 1);
}
//解法1
int combi_1(int n, int r){
  int c = 1; // n_C_0 = 1
  for (int i = 1; i <= r; i++)
  {
    c = c*(n - i + 1)/ i;
  }
  return c;
}

int main()
{
  int n, r;
  scanf("%d %d", &n, &r);

  printf("nCr=%d\n", combi_1(n,r));

  return 0;
}