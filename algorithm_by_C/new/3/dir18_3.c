/**
 *    author:  shosei
 *    created: 03.02.2022 20:00:33
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
  } * t, *p[N], a[] = {"Ann",    18, "Rolla",    19, "Nancy", 16, "Eluza", 17,
                       "Juliet", 18, "Machilda", 20, "Emy",   15, "Candy", 16,
                       "Ema",    17, "Mari",     18};

  //直接選択法を用いて辞書順でソート
  char *min;
  int i, j, minpos;
  for (i = 0; i < N; i++)  //データをポインタで指し示す
    p[i] = &a[i];

  for (i = 0; i < N - 1; i++) {
    min = p[i]->name;
    minpos = i;
    for (j = i + 1; j < N; j++) {
      if (strcmp(min, p[j]->name) > 0) {
        min = p[j]->name;
        minpos = j;
      }
    }
    t = p[i];
    p[i] = p[minpos];
    p[minpos] = t;
  }

  rep(i, N) { printf("%10s%4d\n", p[i]->name, p[i]->age); }
  return 0;
}