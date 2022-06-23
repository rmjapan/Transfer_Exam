/**
*    author:  shosei
*    created: 06.03.2022 06:50:12
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
int A[21],n;
//入力値のMから，Aから選んだ要素を引いていく再帰関数
int solve(int i,int m){
  if(m==0)
    return 1;
  if(i>=n)
    return 0;
  int res = sovle(i+1,m) || solve(i+1, m - A[i]);
  return res;
}

int main()
{
  int q,M,i;

  scanf("%d",&n);
  rep(i,n) scanf("%d",&A[i]);
  scanf("%d",&q);

  for(i=0; i<q; i++){
    scanf("%d",&M);
    if(solve(0,M))
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}