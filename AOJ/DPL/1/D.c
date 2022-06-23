#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define MAX 100000

int n, A[MAX + 1], L[MAX + 1], length;

/*
初めてkey以上となる最小の添字
a[] : 対象のソート済み配列
n : a[]の要素数
key : キー
*/
int bin_search(int a[], int n, int key){
  int left = 0, right = n - 1, mid;

  while(left<=right){
    mid = left + (right - left)/2;
    if(a[mid]>=key)
      if(mid == 0 || mid > 0 && a[mid-1]<key)
        return mid;
      else
        right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}

int lis(){
  L[0]  = A[0];
  int i, j;

  length = 1;
  for(i = 1; i<n; i++){
    if(L[length - 1] < A[i]){
      L[length++] = A[i];
    }else{
      //j:L[j](j=0, ..., lenghth-1)のうち，A[i]以上となる最小の添え字
      j = bin_search(L, length, A[i]);
      L[j] = A[i];
    }
  }
  return length;
}

int main()
{
  scanf("%d", &n);
  rep(i, n) scanf("%d", & A[i]);
  printf("%d\n", lis());
  return 0;
}