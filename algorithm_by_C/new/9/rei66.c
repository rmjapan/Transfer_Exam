/**
*    author:  shosei
*    created: 02.03.2022 05:51:59
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

void backtrack(int);

#define N 8
int column[N+1],
    rup[2*N+1],
    lup[2*N+1],
    queen[N+1]; //王妃の位置

int main()
{
  int i;

  for(i=1; i<=N;i++)
    column[i] = 1;
  for(i=1;i<=2*N; i++)
    rup[i]=lup[i]=1;

  backtrack(1);
  return 0;
}

void backtrack(int i){
  int j,x,y;
  static int num = 0;

  if(i>N){
    printf("\n解 %d \n",++num);
    for(y=1; y<=N; y++){
      for(x=1; x<=N; x++){
        if(queen[y]==x)
          printf(" Q");
        else
          printf(" .");
      }
      printf("\n");
    }
  }else{
    for(j=1;j<=N; j++){
      if(column[j] == 1 && rup[i+j]==1 && lup[i-j+N] == 1){
        queen[i]=j; //王妃の位置
        column[j]=rup[i+j]=lup[i-j+N]=0; //局面の変更
        backtrack(i+1);
        column[j]=rup[i+j]=lup[i-j+N]=1; //局面の戻し
      }
    }
  }
}