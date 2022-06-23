/**
 *    author:  shosei
 *    created: 19.02.2022 22:16:03
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int heap[100];
  int i, n, p, s, m;

  n=1;
  while (scanf("%d", &heap[n]) != EOF) n++;

  m = n-1; //データ数
  for(i=m/2; i>=1; i--){
    p=i;
    s=2*p;
    while(s<=m){
      if(s<m && heap[s+1]<heap[s]) //右と左の小さいほう
        s++;
      if(heap[p]<=heap[s]) //既にヒープの場合
        break;
      swap(&heap[p],&heap[s]);
      p = s; s = 2*p;
    }
  }
  for (i = 1; i < n; i++) {
    if (i > 1) printf(" ");
    printf("%d", heap[i]);
  }
  printf("\n");
  return 0;
}