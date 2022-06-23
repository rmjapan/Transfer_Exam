/**
*    author:  shosei
*    created: 09.06.2021 15:47:10
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int conbi(int n, int r)
{
  if (r == 0 || r == n)
    return 1;
  else
    return conbi(n - 1, r) + conbi(n - 1, r - 1);
}

int main()
{
  int n = 0, r;
  for (n = 0; n <= 5; n++)
  {
    for (int r = 0; r <= n; r++)
    {
      printf("%dC%d=%d  ", n, r, conbi(n, r));
    }
    printf("\n");
  }
  return 0;
}
