/**
 *    author:  shosei
 *    created: 28.01.2022 18:17:58
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define NUM 1000

int main()
{
  int prime[NUM / 2 + 1];
  int i,m = 0, n, limit;
  for (int n = 2; n <=NUM; n++)
  {
    limit = (int)sqrt((double)n);
    for (i = limit; i > 1; i--)
    {
      if (n % i == 0)
        break;
    }
    if (i == 1)
      prime[m++] = n;
  }

  rep(i, m){
    printf("%5d", prime[i]);
    if(i%20 == 19)
      printf("\n");
  }
  printf("\n");
}