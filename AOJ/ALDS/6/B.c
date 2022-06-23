/**
 *    created by: shosei
 *    2022.05.16. 20:13:46
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int A[100000];

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int p, int r) {
  int x, i, j;
  x = A[r];  //ピボット
  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i + 1], &A[r]);
  return i + 1;
}

int main() {
  int n, pivot;
  scanf("%d", &n);
  rep(i, n) scanf("%d", &A[i]);
  pivot = partition(0, n - 1);
  rep(i, n) {
    if (i != 0) printf(" ");
    if (i == pivot) {
      printf("[%d]", A[i]);
      continue;
    }
    printf("%d", A[i]);
  }
  printf("\n");
  return 0;
}