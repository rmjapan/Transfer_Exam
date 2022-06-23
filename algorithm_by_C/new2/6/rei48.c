/**
 *    created by: shosei
 *    2022.06.21. 21:40:29
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int heap[100];
  int n, s, p, m, i;

  n = 1;
  while (scanf("%d", &heap[n]) != EOF) {
    s = n;
    p = s / 2;
    while (s >= 2 && heap[p] > heap[s]) {
      swap(&heap[p], &heap[s]);
      s = p;
      p = s / 2;
    }
    n++;
  }

  m =n-1;
  while(m>1){
    swap(&heap[1], &heap[m]);
    m--;

    p=1; s = 2*p;
    while(s<=m){
      if(s<m && heap[s+1] < heap[s])
        s++;
      if(heap[p] <= heap[s]) break;
      swap(&heap[p], &heap[s]);
      p = s; s = p*2;
    }
  }
  for(i=1; i<n; i++){
    printf("%d ", heap[i]);
  }
  printf("\n");
  return 0;
}