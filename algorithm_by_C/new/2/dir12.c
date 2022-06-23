/**
 *    author:  shosei
 *    created: 30.01.2022 19:10:54
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

double newton(double x[], double y[], int n, double t) {
  static int flag = 1;
  double w[100], sum;    //作業用配列
  static double a[100];  //係数配列

  //係数を求める
  if(flag++==1){
    for(int i = 0; i<n; i++){
      w[i] = y[i];
      for(int j = i -1; j>=0; j--)
        w[j] = (w[j+1]-w[j])/(x[i] - x[j]);
      a[i] = w[0];
    }
  }

  //x=tにおける補間
  sum = a[n-1];
  for(int i = n-2; i>=0; i--){
    sum = sum*(t-x[i]) + a[i];
  }
  return sum;
}

int main() {
  double x[] = {0.0, 1.0, 3.0, 6.0, 7.0}, y[] = {0.8, 3.1, 4.5, 3.9, 2.8};
  double t;

  printf("      x      y\n");
  for (t = 0.0; t <= 7.0; t = t + 0.5) {
    printf("%7.2f%7.2f\n", t, newton(x, y, 5, t));
  }
  return 0;
}