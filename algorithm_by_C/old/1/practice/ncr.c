#include <stdio.h>

long combi(int, int);
long combi_rec(int, int);

int main()
{
  int n, r;
  for (int n = 0; n <= 2; n++)
  {
    for (int r = 0; r <= n; r++)
    {
      printf("%ld ", combi(n, r));
    }
    printf("\n");
  }
}

long combi_rec(int n, int r)
{
  if (r > 0 && n != r)
  {
    return ((n - r + 1) * combi(n, r - 1) / r);
  }
  else if (n == r || r == 0)
  {
    return 1;
  }
}

long combi(int n, int r)
{
  int i;
  long p = 1;
  for (i = 1; i <= r; i++)
  {
    p = p * (n - i + 1) / i;
  }
  return p;
}
