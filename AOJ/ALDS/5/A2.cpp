/**
 *    created by: shosei
 *    11.05.2022 21:39:57
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

bool m_search(vector<int> &a, int m, int left) {
  bool l_flag, r_flag;
  if (m == 0) return true;
  if (left > a.size() - 1 || m < 0) return false;  // left>right

  return m_search(a, m - a[left], left + 1) || m_search(a, m, left + 1);
}

int main() {
  int n, q, m;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> m;
    bool res = m_search(A, m, 0);
    if (res)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}