/**
 *    author:  shosei
 *    created: 30.01.2022 17:46:32
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

#define f(x) ((x) * (x) * (x) + 1)
#define LIMIT 50

//テキトーに符号が入れ替わる区間[a,b]を求める
void find_LandH(double *high, double *low) {
  int flagL = 0, flagH = 0;
  for (double x = -100.0; x <= 100.0; x++) {
    if (f(x) >= 0) {
      *high = x;
      flagH = 1;
    } else {
      *low = x;
      flagL = 1;
    }
    if (flagL * flagH) {
      break;
    }
  }
}

int main() {
  double EPS = 1e-8;
  double low, high, x;
  find_LandH(&high, &low);

  printf("区間[%.1lf,%.1lf]を探索\n", low, high);
  int i;
  for (i = 0; i < LIMIT; i++) {
    x = (high + low) / 2;
    if (f(x) > 0)
      high = x;
    else
      low = x;
    if (f(x) == 0 || fabs(high - low) < EPS * fabs(low)) {
      printf("x = %lf\n", x);
      break;
    }
  }
  if (i == LIMIT) printf("収束しない\n");

  return 0;
}