/**
*    author:  shosei
*    created: 28.01.2022 17:36:38
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int main()
{
  int m,n;
  printf("(m,n) = ?\n");
  scanf("%d %d", &m, &n);
  int n_0 = n, m_0 = m;
  while (m != n)
  {
    if(m>n){
      m = m - n;
    }else{
      n = n - m;
    }
  }
  printf("GCD(%d,%d) = %d\n", m_0, n_0, m);

  return 0;
}