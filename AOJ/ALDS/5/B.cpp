/**
*    created by: shosei
*    13.05.2022 23:34:07
**/
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define INFTY 2000000000
#define MAX 500000

int count_cmp = 0; //比較回数
int L[MAX/2 + 2], R[MAX/2 + 2];

void merge(vector<int> &A, int left, int mid, int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  //部分配列L,RへAの[left, right]要素を格納
  for(i = 0; i<n1; i++)
    L[i] = A[left + i];
  for(i = 0; i<n2; i++)
    R[i] = A[mid + i];


  //マージ
  L[n1] = INFTY; //番兵
  R[n2] = INFTY;
  i = j = 0;
  for(k = left; k<right; k++){
    count_cmp++;
    if(L[i] <=R[j]) //番兵が来れば片方だけずっと実行される
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

void mergeSort(vector<int> &A, int left, int right){
  int mid;
  if(left+1>=right) return;

  mid = (right+left)/2;

  //分割
  mergeSort(A, left, mid);
  mergeSort(A, mid, right);
  merge(A, left, mid, right);
}



int main()
{
  int n;
  cin>>n;
  vector<int> S(n);
  rep(i, n) cin>>S[i];

  mergeSort(S, 0, n);
  rep(i, n) {
    if(i != 0) cout<<" ";
    cout<<S[i];
  }
  cout<<endl;
  cout<<count_cmp<<endl;

  return 0;

}