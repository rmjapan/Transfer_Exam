/**
 *    author:  shosei
 *    created: 05.02.2022 22:02:24
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N 10

int main() {
  int a[] = {2, 3, 7, 11, 31, 50, 55, 70, 77, 80};
  int low, mid, high, key;
  printf("key?");
  scanf("%d", &key);

  low = 0;
  high = N - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] == key) {
      low = mid + 1;
      high = mid - 1;
    } else if (a[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (low == high + 2) {
    printf("%dは%d番目にありました\n", a[mid], mid);
  } else {
    printf("見つかりませんでした\n");
  }
  return 0;
}