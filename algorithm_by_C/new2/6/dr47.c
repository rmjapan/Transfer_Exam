#include<stdio.h>

void swap(int *a, int *b){int tmp;tmp = *a;*a = *b;*b = tmp;}

int main(void){
  int heap[100];
  int i,n,p,s,m;

  n=1;
  while(scanf("%d", &heap[n]) != EOF)
    n++;

  m = n-1; //データ数
  for(i=m/2;i>=1; i--){
    p=i;
    s=2*p;
    while(s<=m){
      if(s<m && heap[s+1]<heap[s])
        s++; //右の子が小さければsを更新
      if(heap[p]<=heap[s])
        break;
      swap(&heap[p], &heap[s]); //heap[p]>heap[s]
      p=s; s = 2*p;
    }
  }

  for(i = 1; i<=m; i++)
    printf("%d ", heap[i]);
  printf("\n");
  return 0;
}