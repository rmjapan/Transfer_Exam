/**
 *    author:  shosei
 *    created: 02.03.2022 07:29:56
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);


#define limit 8  //ナップサックの従量制現値
#define n 5      //品物の種類
#define min 1    //重さの最小値

int main() {
  struct body {
    char name[20];
    int size;
    long price;
  } a[] = {{"plum", 4, 4500},
           {"apple", 5, 5700},
           {"orange", 2, 2250},
           {"strawberry", 1, 1100},
           {"melon", 6, 6700}};
  long newvalue, value[limit + 1];
  int item[limit + 1], i, s, p;

  for (s = 0; s <= limit; s++) value[s] = 0;

  for (i = 0; i < n; i++) {
    for (s = a[i].size; s <= limit; s++) {
      p = s - a[i].size;  //空きサイズ
      newvalue = value[p] + a[i].price;
      if (newvalue > value[s]) {
        value[s] = newvalue;
        item[s] = i;  //最適解の更新
      }
    }
  }
  printf("   品 目  価格\n");
  for (s = limit; s >= min; s = s - a[item[s]].size)
    printf("%10s%5ld\n", a[item[s]].name, a[item[s]].price);
  printf("合 計 %5ld\n", value[limit]);
  return 0;
}