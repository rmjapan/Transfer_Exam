/**
 *    author:  shosei
 *    created: 28.01.2022 19:49:54
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

int main()
{
  int n,a;
  while (printf("Number?:"), scanf("%d",&n) != EOF){
    a = 2;
    while(n>=a*a){
      if(n % a == 0){
        printf("%d*", a);
        n = n / a;
      }else
        a++;
    }
    printf("%d\n", n);
  }
  return 0;
}