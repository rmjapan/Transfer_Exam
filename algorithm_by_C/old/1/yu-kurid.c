#include <stdio.h>

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);

  while (1)
  {
    if (a > b)
    {
      a = a - b;
    }
    else if (a < b)
    {
      b = b - a;
    }
    else
    {
      printf("GCD = %d\n", a);
      return 0;
    }
  }
}
