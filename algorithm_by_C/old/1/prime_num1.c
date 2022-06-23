#include <stdio.h>
#include <math.h>
#define NUM 1000

void main(void)
{
  int i, n, Limit;
  int prime[NUM / 2 + 1];
  int index = 1;
  int input[NUM];
  int stp_flag = -1;

  for (int i = 0; i < NUM; i++)
  {
    input[i] = i;
  }

  for (int j = 0; j < NUM; j++)
  {
    n = input[j];
    if (n >= 2)
    {
      Limit = (int)sqrt((double)n);
      for (i = Limit; i > 1; i--)
      {
        if (n % i == 0)
          break;
      }
      if (i == 1)
      {
        prime[index] = n;
        index++;
      }
    }
  }
  prime[index] = stp_flag;

  i = 1;
  while (prime[i] != stp_flag)
  {
    printf("%3d ", prime[i]);
    if (i % 15 == 0) printf("\n");
    i++;
  }
  printf("\n");
}
