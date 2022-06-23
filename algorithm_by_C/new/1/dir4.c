/**
 *    author:  shosei
 *    created: 26.01.2022 23:36:43
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N 20

int irnd(int n)
{
  return (int)(rand() / (RAND_MAX + 0.1) * n + 1);
}

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main()
{
  srand((unsigned int)time(NULL));
  int a[N + 1];
  int j;
  for (int i = 1; i <= N; i++)
  {
    a[i] = i;
  }

  // for (int i = 1; i <= N - 2; i++)
  // {
  //   j = irnd(N - i);
  //   swap(&a[j], &a[N- i +1]);
  // }

  for (int i = N; i > 1; i--){
    j = irnd(i - 1);
    swap(&a[i], &a[j]);
  }

    for (int i = 1; i <= N; i++)
      printf("%d ", a[i]);
  printf("\n");
  return 0;
}