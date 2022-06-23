/**
*    author:  shosei
*    created: 29.01.2022 16:46:27
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

unsigned rndnum = 13; //乱数の初期値
unsigned irnd(void);

int main()
{
  for (int j = 0; j < 100; j++){
    printf("%8d", irnd());
    if(j % 20 == 19)
      printf("\n");
  }
  printf("\n");
  return 0;
}

unsigned irnd(){
  rndnum = (109 * rndnum + 1021) % 32768;
  return rndnum;
}