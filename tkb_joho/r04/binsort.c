/**
 *    author:  shosei
 *    created: 25.03.2022 16:18:12
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 10

//変更前
void bin_sort(int a[], int n) {
  int i, j, bin[M + 1];
  for (i = 0; i <= M; i++)  //ビンを空にする
    bin[i] = -1;

  for (i = 0; i < n; i++)  //ビンにデータを振り分ける
    bin[a[i]] = a[i];

  j = 0;
  for (i = 0; i <= M; i++) {
    if (bin[i] != -1) a[j++] = bin[i];
  }
}

void bin_sort2(int a[], int n) {
  int i, j, bin[M + 1];
  for (i = 0; i <= M; i++)  //ビンを空にする
    bin[i] = -1;

  for (i = 0; i < n; i++)  //度数分布を求める
    if (bin[a[i]] != -1)
      bin[a[i]]++;
    else
      bin[a[i]] = 1;

  j = 0;
  for (i = 0; i <= M; i++) {
    if (bin[i] != -1) {
      while (bin[i] != 0) {
        a[j++] = i;
        bin[i]--;
      }
    }
  }
}

//改善ver
// void bin_sort2(int a[], int n) {
//   int i, j, bin[M + 1];
//   for (i = 0; i <= M; i++)  //ビンを空にする
//     bin[i] = -1;
//   //度数分布を求める, -1は空状態，0以上ならなにか入っている状態
//   //0を空にした方がわかりやすいかもしれない
//   for (i = 0; i < n; i++)
//       bin[a[i]]++;

//   j = 0;
//   for (i = 0; i <= M; i++) {
//     if (bin[i] != -1) {
//       while (bin[i]-- != -1) {
//         a[j++] = i;
//       }
//     }
//   }
// }
void print_data(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int n = 5;
  int a1[] = {3, 1, 4, 8, 4};
  // print_data(a1, 5);
  printf("変更前:");
  bin_sort(a1, n);
  print_data(a1, n);

  printf("変更後:");
  bin_sort2(a1, n);
  print_data(a1, n);
  return 0;
}