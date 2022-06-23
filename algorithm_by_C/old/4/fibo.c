/**
*    author:  shosei
*    created: 10.06.2021 14:53:07
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N 10
long fib(long n)
{
  long a, b, tmp;
  a = 1L;
  b = 1L;
  for (int i = 3; i <= n; i++)
  {
    tmp = b;
    b = a + b;
    a = tmp;
  }
  return b;
}

int main()
{
  for (int i = 1; i <= N; i++)
    printf("%d: %ld\n", i, fib(i));
  return 0;
}
