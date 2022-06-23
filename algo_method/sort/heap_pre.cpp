/**
 *    created by: shosei
 *    22.06.2022 10:23:46
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
using vi = vector<int>;
using vii = vector<vi>;
using graph = vii;

void shiftdown(int p, int N, int A[]) {
  int ch;
  ch = 2 * p + 1;
  while (ch < N) {
    if (ch < N-1 && A[ch + 1] > A[ch]) ch++;
    if (A[p] >= A[ch]) break;
    swap(A[p], A[ch]);
    p = ch;
    ch = 2 * p + 1;
  }
}

int main() {
  int N, M;
  int p, child;
  int A[100001];
  cin >> N >> M;

  for (int i = 0; i < N; i++) cin >> A[i];

  for (int i = N / 2 - 1; i >= 0; i--) shiftdown(i, N, A);

  int i = N-1;
  while (i > 0) {
    swap(A[0], A[i]);
    shiftdown(0, i, A);
    if (i == M) {
      for (int i = 0; i < N; i++) printf("%d ", A[i]);
      printf("\n");
    }
    i--;
  }

  for (int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

  return 0;
}