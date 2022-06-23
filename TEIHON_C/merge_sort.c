/**
 *    created by: shosei
 *    29.04.2022 11:14:55
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define MAX_ELEMENTS 10000

int b[MAX_ELEMENTS];  //作業用配列

void merge_sort(int a[], int left, int right) {
  int mid;
  int i, j, k;  // i:部分数列の左端，j:部分数列の右端, k:結果格納用のポインタ

  //ベースケース
  if(left>=right) return;

  mid = left + (right - left) / 2;

  //分割
  merge_sort(a, left, mid);
  merge_sort(a, mid + 1, right);

  //部分数列を作業用配列へ格納
  for (i = left; i <= mid; i++) b[i] = a[i];
  //部分数列の後半を逆順で格納
  for (j = right, i = mid+1; j >= mid + 1; i++,j--) b[i] = a[j];

  //部分数列のマージ
  i = left;
  j = right;
  for (k = left; k <= right; k++) {
    if (b[i] <= b[j])
      a[k] = b[i++];
    else
      a[k] = b[j--];
  }
}

int main() {
  int a[] = {2, 1, 3, 3, 4, 5, 10};
  merge_sort(a, 0, 6);
  rep(i, 7){
    printf("%d, ", a[i]);
  }
  printf("\n");
  return 0;
}