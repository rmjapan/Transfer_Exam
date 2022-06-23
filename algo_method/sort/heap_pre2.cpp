/**
 *    created by: shosei
 *    22.06.2022 10:52:39
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  for (int x = N / 2 - 1; x >= 0; x--) {
    int k = x;
    int s = 2 * k + 1;
    while (s < N) {
      if (s < N-1 && A[s] < A[s + 1]) s++;
      if (A[k] >= A[s]) break;
      swap(A[k], A[s]);
      k = s;
      s = 2 * k + 1;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}