/**
 *    created by: shosei
 *    2022.05.09. 10:57:09
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int search1(int data[], int value, int left, int right) {
  int i;
  for (i = left; i <= right; i++)
    if (value == data[i]) return i;
  return -1;
}

int search2(int data[], int value, int left, int right) {
  int middle;
  while (left <= right) {
    if (value == data[middle])
      return middle;
    else if (value < data[middle])
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;
}

int main() {
  int x[] = {1, 2, 3, 4, 5, 6};
  printf("%d\n", search1(x, 3, 0, 5));
  printf("%d\n", search2(x, 3, 0, 5));
  return 0;
}