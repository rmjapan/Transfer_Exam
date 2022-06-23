/**
*    author:  shosei
*    created: 28.05.2021 22:11:59
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
int binsearch1(int a[], int n, int key)
{
  int left = 0, right = n - 1, mid;
  while (left <= right)
  {
    mid = left + (right - left) / 2;
    if (key < a[mid])
      right = mid - 1;
    else if (key > a[mid])
      left = mid + 1;
    else
      return mid;
  }
}

int binsearch2(int a[], int n, int key)
{
  int i = binsearch1(a, n, key), j;
  pra(i) if (i != -1)
  {
    for (j = i; j >= 0; j--)
    {
      if (a[j] < key)
        return j + 1;
    }
    return 0;
  }
  else return -1;
}

int binsearch3(int a[], int n, int key)
{
  int left = 0, right = n - 1, mid;
  while (left <= right)
  {
    mid = left + (right - left) / 2;
    if (key < a[mid])
      right = mid - 1;
    else if (key > a[mid])
      left = mid + 1;
    else if (mid == 0 || a [mid - 1] < key) //一番左にキーがある時注意
      return mid;
    else
      right = mid -1;
  }
  return -1;
}

int main()
{
  int a[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 9};
  int n = 10, key = 5;
  int res;

  res = binsearch3(a, n, key);
  pra(res)

      return 0;
}