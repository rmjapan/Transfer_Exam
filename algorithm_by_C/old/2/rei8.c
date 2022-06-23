/**
 *    author:  shosei
 *    created: 26.04.2021 21:53:41
 **/
#include <stdio.h>
unsigned rndnum = 13;
unsigned irnd(void);

int main()
{
  int j;
  for (j = 0; j < 100; j++)
  {
    printf("%8d", irnd());
  }
  printf("\n");
  return 0;
}
unsigned irnd(void)
{
  rndnum = (rndnum * 109 + 1021) % 32768;
  return rndnum;
}
