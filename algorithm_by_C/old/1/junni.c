#include <stdio.h>
#define Num 10
int main()
{
  int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
  int juni[Num];

  for (int i = 0; i < Num; i++)
  {
    juni[i] = 1;
    for (int j = 0; j < Num; j++)
    {
      if (a[i] < a[j] && i != j)
        juni[i]++;
    }
  }

  for (int i = 0; i < 10; i++)
    printf("%3d : %d\n", a[i], juni[i]);

  return 0;
}
