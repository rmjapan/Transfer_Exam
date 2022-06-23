#include <stdio.h>
#define N 12
long conbi(int n, int r)
{
  if (r == 0 || r == n)
    return 1;
  return conbi(n - 1, r - 1) + conbi(n - 1, r);
}

int main()
{
  int n, r, t;
  for (n = 0; n <= N; n++)
  {
    for (t = 3*(N - n); t >= 0; t--)
    {
      printf(" ");
    }
    for (r = 0; r <= n; r++)
    {
      printf("%3ld   ", conbi(n, r));
    }
    printf("\n");
  }
}