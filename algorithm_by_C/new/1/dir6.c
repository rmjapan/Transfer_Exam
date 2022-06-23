/**
*    author:  shosei
*    created: 28.01.2022 17:42:35
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int gcd(int m, int n){
  int k;
  do{
    k = m % n;
    m = n;
    n = k;
  } while (k != 0);
  return m;
}

int gcd2(int m, int n){
  if(n == 0)
    return m;
  return gcd(n, m % n);
}
int gcd3(int m, int n){
  return (n == 0) ? m : gcd(n, m % n);
}
int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  printf("GCD(%d, %d) = %d\n", m, n, gcd3(m, n));
  return 0;
}

int lcm(int a, int b) {
return a / gcd(a, b) * b;
}