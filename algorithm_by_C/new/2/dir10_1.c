/**
 *    author:  shosei
 *    created: 30.01.2022 16:47:18
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

double myexp(double x) {
  double EPS = 1e-8;
  double d, s = 1.0, e = 1.0;
  double true_x = x;
  x = fabs(x);
  for (int k = 1; k <= 200; k++) {
    d = s;
    e = e * x / k;
    s = s + e;
    if (fabs(s - d) < EPS * fabs(d))
      if (true_x >= 0)
        return s;
      else
        return 1.0 / s;
  }
  return 0.0;  //収束しない時
}

int main() {
  double x;
  printf("      x         myexp(x)            exp(x)\n");
  for (x = -40; x <= 40; x = x + 10) {
    printf("%5.1lf%14.6g%14.6g\n", x, myexp(x), exp(x));
  }
  printf("%lf", myexp(1));

  return 0;
}