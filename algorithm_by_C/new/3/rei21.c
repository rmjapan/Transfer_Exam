/**
 *    author:  shosei
 *    created: 04.02.2022 20:00:10
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
  int pos = 0, flag = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] == key) {
      printf("%d は%d番目にありました", a[mid], mid);
      flag = 1;
      break;
    } else if (a[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (flag != 1) printf("Not faund\n");
  return 0;
}