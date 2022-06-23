/**
*    author:  shosei
*    created: 17.05.2021 22:51:58
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main()
{
  int a[] = {80, 41, 35, 90, 40, 20};
  int n = sizeof(a) / sizeof(int);
  int min, min_i;
  for (int i = 0; i <= n - 2; i++)
  {
    min = a[i];
    min_i = i;
    for (int j = i + 1; j <= n - 1; j++)
    {
      if (min > a[j])
      {
        min_i = j;
        min = a[j];
      }
    }
    swap(&a[i], &a[min_i]);
  }
  rep(i, n) printf("%d ", a[i]);
  return 0;
}
