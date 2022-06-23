/**
 *    author:  shosei
 *    created: 20.02.2022 21:46:03
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

void shiftdown(int p, int n, int heap[])  // 下方移動
{
  int s;
  s = 2 * p;
  while (s <= n) {
    if (s < n && heap[s + 1] > heap[s])  // 左と右の子の小さい方
      s++;
    if (heap[p] >= heap[s]) break;
    swap(&heap[p], &heap[s]);
    p = s;
    s = 2 * p;  // 親と子の位置の更新
  }
}

int main() {
  int heap[100];
  int i, n, m;

  n = 1;
  while (scanf("%d", &heap[n]) != EOF) n++;
  m = n - 1;
  for (i = m / 2; i >= 1; i--) shiftdown(i, m, heap);

  while (m > 1) {
    swap(&heap[1], &heap[m]);
    m--;
    shiftdown(1, m, heap);
  }

  for (i = 1; i < n; i++) printf("%d ", heap[i]);
  printf("\n");
  return 0;
}