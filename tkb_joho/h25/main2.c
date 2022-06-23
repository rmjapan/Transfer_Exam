//
//  main.c
//  H25(4)
//
//  Created by 水野桃夏 on 2020/03/22.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>

int count;
int count2 = 0;

void exch(int a[], int i, int j) {
  int tmp;
  tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int partition(int a[], int p, int r) {
  int i, j, x;
  x = a[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    count2++;
    if (a[j] <= x) {
      i = i + 1;
      exch(a, i, j);
      //            printf("i=%d,j=%d\n",i,j);
    }
  }
  exch(a, r, i + 1);
  return i + 1;
}

void sort(int a[], int p, int r) {
  int q;
  if (p < r) {
    q = partition(a, p, r);
    sort(a, p, q - 1);
    sort(a, q + 1, r);
  }
}
int selection(int a[], int p, int r, int i) {
  int q, k;
  count++;
  if (p == r) return a[p];
  q = partition(a, p, r);
  k = q - p;
  //    printf("%d ",q);
  if (i == k)
    return a[q];
  else if (i < k)  //この部分でa[i]を含む部分数列へアクセスしている
    return selection(a, p, q - 1, i);
  else
    return selection(a, q + 1, r, i - (k + 1));
}
int main(void) {
  int a1[] = {5, 10, 7, 12, 8, 9};
  int a4[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int a5[] = {3, 4, 2, 1, 0};
  int a6[] = {1, 3, 2, 0, 4};  //(5)の答えの一つ
  int i;
  selection(a6, 0, 4, 2);
  printf("%d\n", count);
  //    sort(a1, 0, 5);
  //    for(i=0;i<6;i++){
  //        printf("%d ",a1[i]);
  //    }
  return 0;
}