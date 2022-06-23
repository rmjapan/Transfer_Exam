/**
*    author:  shosei
*    created: 30.01.2022 17:19:03
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

#define PI 3.14159265

double mycos(double x){
  double EPS = 1e-8;
  double s = 1.0, c = 1.0, d;
  x = fmod(x,2*PI);
  for(int k = 2; k<=200; k = k+2){
    d = s;
    c = -c*x*x/((k-1)*k);
    s = s+c;
    if(fabs(s-d)<EPS*fabs(d))
      return s;
  }
  return 9999.0;
}

int main()
{
  double x;
  double rd = PI / 180;
  printf("     x        mycos(x)        cos(x)\n");
  for(x = 0.0; x<=180.0; x = x + 10){
    printf("%5.1lf%14.6lf%14.6lf\n",x, mycos(x*rd), cos(x*rd));
  }
  return 0;
}