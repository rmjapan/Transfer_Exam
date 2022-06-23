/**
*    author:  shosei
*    created: 28.01.2022 17:18:35
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define N 100000

double rnd(){
  return (double)rand() / (RAND_MAX + 0.1);
}

double ellipse(double x, double y){
  return x * x / 4 + y * y;
}

int main()
{
  srand((unsigned int)time(NULL));
  double x, y,s;
  int in = 0;
  rep(i,N){
    x = 2*rnd();
    y = rnd();
    if(ellipse(x,y) <= 1)
      in++;
  }

  s = 8.0 * in / N;
  printf("楕円の面積 = %lf\n", s);
  return 0;
}