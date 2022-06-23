/**
 *    author:  shosei
 *    created: 04.02.2022 19:10:30
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
  struct girl {
    char name[20];
    int age;
  } a[N + 1] = {"Ann",   18,       "Rolla", 19,         "Nancy", 16,    "Eluza",
                17,      "Juliet", 18,      "Machilda", 20,      "Emy", 15,
                "Candy", 16,       "Ema",   17,         "Mari",  18};
  char key[20];

  printf("検索するdata ？");
  scanf("%s", key);

  strcpy(a[N].name, key);

  //逐次サーチ
  int i = 0;
  while (strcmp(key, a[i].name) != 0) i++;

  if (i == N)
    printf("見つかりませんでした");
  else
    printf("%s %d\n", a[i].name, a[i].age);
  return 0;
}