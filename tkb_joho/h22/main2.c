//
//  main.c
//  h22(4)
//
//  Created by 水野�?�? on 2020/04/21.
//  Copyright © 2020 水野�?�?. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void prefixsum(int m, int n, int a[], int c[]) {
  int i;
  for (i = 0; i < n; i++) {
    c[i] = 0;
  }
  for (i = 0; i < n; i++) {
    c[a[i]]++;
  }
  for (i = 1; i < m; i++) {
    c[i] += c[i - 1];
  }
}

void sort(int m, int n, int a[], int b[]) {
  int i, *c, j;
  c = malloc(m * sizeof(*c));
  prefixsum(m, n, a, c);
  for (i = n - 1; i >= 0; i--) {
    b[--c[a[i]]] = a[i];
    // b[c[a[i]] - 1] = a[i];
    // c[a[i]]--;

    // b�̗v�f��a�̗v�f�����΂��܂������Ȃ���
    //  j = 1;while (b[c[a[i]] - j] == a[i])
    //      j++;
    //  b[c[a[i]] - j] = a[i];
  }
}

int main(int argc, const char *argv[]) {
  int m = 8, n = 7, i;
  int a[] = {1, 5, 2, 7, 5, 5, 4};
  int b[7];
  for (int i = 0; i < 7; i++) b[i] = -1;
  sort(m, n, a, b);
  for (i = 0; i < n; i++) printf("%d ", b[i]);
  return 0;
}
