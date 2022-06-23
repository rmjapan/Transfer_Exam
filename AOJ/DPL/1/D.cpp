/**
 *    created by: shosei
 *    02.06.2022 22:10:01
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define MAX 100000

int n, A[MAX], L[MAX];

int binsearch3(int a[], int n, int key) {
  int left = 0, right = n-1, mid;
  while (left <= right) {
    mid = (left + right) / 2;

    if (a[mid] >= key)
      if (mid == 0 || a[mid - 1] < key)
        return mid;
      else
        right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

int lis() {
  L[0] = A[0];
  int i, j, length = 1;

  for (i = 1; i < n; i++) {
    if (L[length - 1] < A[i]) {
      L[length++] = A[i];  //最長増加部分列にA[i]を追加
    } else {
      // L[j](j = 0, ... , length-1)の中で，A[i]以上となる最初のj
      j = binsearch3(L, length, A[i]);
      //*lower_bound(L, L + length, A[i]) = A[i];
      L[j] = A[i];
    }
  }
  return length;
}

int main() {
  cin >> n;
  rep(i, n) cin >> A[i];
  cout << lis() << endl;
}