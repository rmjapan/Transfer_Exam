/**
 *    author:  shosei
 *    created: 19.02.2022 22:07:48
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
  int n, i, s, p, w;

  n = 1;
  while (scanf("%d", &heap[n]) != EOF) {
    s = n;
    p = s / 2;
    while (heap[p] > heap[s]) {
      swap(&heap[p], &heap[s]);
      s = p;
      p = s / 2;
    }
    n++;
  }
  for (i = 1; i < n; i++) {
    if (i > 1) printf(" ");
    printf("%d", heap[i]);
  }
  printf("\n");
  return 0;
}