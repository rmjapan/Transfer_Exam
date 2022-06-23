/**
 *    author:  shosei
 *    created: 29.01.2022 17:51:20
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

#define PI 3.1415926535
int hist[100];
void brnd(double, double, double *, double *);

int main()
{
  srand((unsigned int)time(NULL));
  int i, j;
  double x, y;

  for (i = 0; i < 1000; i++)
  {
    brnd(2.5, 10.0, &x, &y);
    hist[(int)x]++;
    hist[(int)y]++;
  }

  for (i = 0; i <= 20; i++)
  {
    printf("%3d : I ", i);
    for (j = 1; j <= hist[i] / 10; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}

void brnd(double sig, double m, double *x, double *y){
  double r1, r2;
  r1 = rand() / (RAND_MAX + 0.1);
  r2 = rand() / (RAND_MAX + 0.1); //0<=r<1の乱数を発生

  *x = sig * sqrt(-2 * log(r1)) * cos(2 * PI * r2) + m;
  *y = sig * sqrt(-2 * log(r1)) * sin(2 * PI * r2) + m;
}