/**
 *    created by: shosei
 *    2022.06.21. 19:04:37
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
  int n, s, p, w;
  n = 1;
  while (scanf("%d", &heap[n]) != EOF) {
    s = n;
    p = s / 2;
    while (p > 1 && heap[p] > heap[s]) {
      swap(&heap[p], &heap[s]);
      s = p;
      p = s / 2;
    }
    n++;
  }
  for (int i = 1; i < n; i++) printf("%d ", heap[i]);  // n:要素数+1
  printf("\n");
  return 0;
}