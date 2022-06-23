/**
 *    author:  shosei
 *    created: 25.03.2022 17:04:48
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 10
//結果はbに格納
void dist_count_sort(int a[], int b[], int n) {
  int count[M + 1];
  int i;

  for (i = 0; i <= M; i++)  //キーの出現回数を初期化
    count[i] = 0;

  for (i = 0; i < n; i++)  //キーの出現回数を調べる
    count[a[i]]++;

  for (i = 0; i < M; i++)  //数え上げたキーの累積度数分布表を求める
    count[i + 1] += count[i];

  //度数分布に従ってデータを配列aから配列bにコピーする
  //後ろから調べるのは安定なソートにするため
  for (i = n - 1; i >= 0; i--) b[--count[a[i]]] = a[i];
}

void print_data(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int n = 5;
  int a1[] = {3, 1, 4, 8, 4};
  int b[100];
  dist_count_sort(a1,b, n);
  print_data(b, n);

  return 0;
}