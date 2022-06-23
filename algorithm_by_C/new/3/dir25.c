/**
 *    author:  shosei
 *    created: 07.02.2022 21:47:51
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

#define TableSize 1000
#define ModSize 1000

int hash(char *);

struct tel {  //データテーブル
  char name[12];
  char telnum[12];
  int empty;
} dat[TableSize];

int main() {
  int n;
  char a[12], b[12];

  printf("名前 電話番号\n");
  while (scanf("%s %s", a, b) != EOF) {  //データの入力
    n = hash(a);
    while (dat[n].empty == 1 && n < TableSize) n++;
    if (n < TableSize) {
      strcpy(dat[n].name, a);
      strcpy(dat[n].telnum, b);
      dat[n].empty = 1;
    }else
      printf("表がいっぱいです\n");
  }

  rewind(stdin);
  printf("検索するデータを入力してください\n");
  while (scanf("%s", a) != EOF) {
    n = hash(a);
    while(strcmp(a,dat[n].name) != 0 && n<TableSize) n++;
    if(n<TableSize)
    printf("%15s%15s\n", dat[n].name, dat[n].telnum);
    else
      printf("データは見つかりませんでした");
  }
  return 0;
}

int hash(char a[]) {
  int n;
  n = strlen(a);
  return ((a[0] - 'A') + (a[n / 2 - 1] - 'A') * 26 +
          (a[n - 2] - 'A') * 26 * 26) %
         ModSize;
}