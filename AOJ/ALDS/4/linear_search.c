#include <stdio.h>

int search(int A[], int n, int key) {
  int i = 0;
  A[n] = key;
  while (A[i] != key) i++;
  return i != n;
}

int main() {
  int n,q;
  int C = 0;
  int S[10000],T;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &S[i]);
  
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d",&T);
    if(search(S, n, T)) C++;
  }

  printf("%d\n",C);



}