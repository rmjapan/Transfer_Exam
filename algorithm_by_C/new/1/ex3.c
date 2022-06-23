/**
*    author:  shosei
*    created: 24.01.2022 23:24:29
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define NUM 10



int main()
{
  int a[] = {56, 25, 67, 88, 100, 61, 55, 67, 76, 56};
  int rank[NUM];
  rep(i,NUM){
    rank[i] = 1; //順位の初期化
  }

  for (int i = 0; i<NUM; i++){
    for (int j = 0; j<NUM; j++){
      if(a[i]<a[j]){
        rank[i]++;
      }
    }
  }
  printf("  順位  得点\n");
  rep(i, NUM) printf("%6d%6d\n", a[i], rank[i]);
  return 0;
}