/**
 *    author:  shosei
 *    created: 19.02.2022 23:12:57
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

int binary_search(int A[], int n, int key) {
  int left, right, mid;

  left = 0;
  right = n;
  while (left <= right) {
    mid = (left + right) / 2;
    if (A[mid] == key)
      return 1;
    else if (A[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return 0;
}

int main() {
  int n, q;
  int C = 0;
  int S[100000], T;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &S[i]);

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &T);
    if (binary_search(S, n, T)) C++;
  }

  printf("%d\n", C);

  return 0;
}