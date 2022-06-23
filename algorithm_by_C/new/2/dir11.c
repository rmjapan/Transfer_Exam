/**
*    author:  shosei
*    created: 30.01.2022 18:18:08
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)

#define LIMIT 50
#define EPS 1e-8

int main()
{
  double x = -2.0, pre_x;
  int i = 0;
  for(i = 0; i<LIMIT; i++){
    pre_x = x;
    x = x - f(x)/g(x);
    if(fabs(x - pre_x)<EPS*fabs(pre_x)){
      printf("x=%lf\n",x);
      break;
    }
  }
  if(i == LIMIT)
    printf("収束しない\n");
  return 0;
}