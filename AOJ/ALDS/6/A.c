/**
 *    created by: shosei
 *    2022.05.16. 20:32:15
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define MAX_COUNT 10000
#define MAX_RANGE 2000000

int A[MAX_RANGE + 1], B[MAX_RANGE+1], C[MAX_COUNT + 1];

void countingSort(int n, int k) {
  int i, j;

  for (i = 0; i <= k; i++) C[i] = 0;

  for (j = 0; j < n; j++) C[A[j]]++;

  for (i = 1; i <= k; i++) {
    C[i] = C[i] + C[i - 1];
  }

  for (j = n - 1; j >=0; j--) {
    B[--C[A[j]]] = A[j];
  }
}

int main() {
  int n, k = -1;
  scanf("%d", &n);
  //入力しながらkを求める
  rep(i, n) {
    scanf("%d", &A[i]);
    if (k < A[i]) k = A[i];
  }

  countingSort(n, k);
  rep(i, n) {
    if (i != 0) printf(" ");
    printf("%d", B[i]);
  }
  printf("\n");
  return 0;
}