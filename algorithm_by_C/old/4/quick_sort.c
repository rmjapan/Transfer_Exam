/**
*    author:  shosei
*    created: 12.06.2021 14:32:26
**/
#include <stdio.h>
#define N 10

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void quick_sort(int *a, int left, int right)
{
  int axis,i, j;

  //再帰の出口left<right
  if(left<right)
  {
    axis = a[(left+right)/2];
    i = left;
    j = right; //while(a[--j]>s)の部分の調整
    while(1){
      while(a[i++] < axis)
        ;
      while(a[j--] > axis)
        ;
      i--;
      j++;
      if(i>=j)
        break;
      swap(&a[i], &a[j]);
    }
    quick_sort(a, left, i - 1);
    quick_sort(a, j + 1, right);
  }
}

int main()
{
  static int a[] = {41, 24, 76, 11, 45, 64, 21, 69, 19, 36};
  quick_sort(a, 0, N - 1);
  for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}
