/**
 *    author:  shosei
 *    created: 30.01.2022 18:50:59
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

double lagrange(double x[],double y[], int n, double t){
  double sum,p;

  sum = 0.0;
  for(int i = 0; i<n;i++){
    p = y[i];
    for(int j = 0; j<n; j++){
      if(i!=j)
        p *= (t-x[j])/(x[i]-x[j]);
    }
    sum += p;
  }
  return sum;
}

int main() {
  double x[] = {0.0, 1.0, 3.0, 6.0, 7.0}, y[] = {0.8, 3.1, 4.5, 3.9, 2.8};
  double t;

  printf("      x      y\n");
  for(t=0.0; t<=7.0; t=t+0.5){
    printf("%7.2f%7.2f\n",t,lagrange(x,y,5,t));
  }
  return 0;
}