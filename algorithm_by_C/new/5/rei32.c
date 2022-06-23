/**
*    author:  shosei
*    created: 14.02.2022 17:14:13
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

#define MaxSize 100  // スタック・サイズ

int stack[MaxSize];
int sp = 0;

void push(int a){
  if(sp == MaxSize){
    printf("stack overflow\n");
    exit(-1);
  }
  stack[sp++] = a;
}

void pop(int *a){
  if(sp == 0){
    printf("stack is empty\n");
    exit(-1);
  }
  *a = stack[--sp];
}

int main()
{
  int c,n;

  while(printf("]"),(c =getchar())!=EOF){
    rewind(stdin);
    if(c=='i' || c== 'I'){
      printf("data-> ");
      scanf("%d",&n);rewind(stdin);
      push(n);
    }
    if(c=='o' || c== 'O'){
      pop(&n);
      printf("stack data--> %d\n",n);
    }
  }
  return 0;
}