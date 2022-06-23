/**
*    author:  shosei
*    created: 10.06.2021 14:26:02
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int gcd(int m, int n)
{
  return n ? gcd(n, m % n) : m;
}

int gcd2(int m, int n){
  if(n == 0)
    return m;
  else
    return gcd(n, m % n);
}

int main()
{
  printf("%d", gcd2(5, 10));
  return 0;
}
