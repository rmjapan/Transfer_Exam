/**
 *    author:  shosei
 *    created: 08.02.2022 18:16:06
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

#define N 4
int p[N + 2] = {' ', 'a', 'c', 'h', 't'};

void perm(int);
void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int i;

  // for (i = 1; i <= N; i++) p[i] = i;
  perm(1);
  return 0;
}

void perm(int i) {
  int k, j, t;
  if (i < N) {
    for (j = i; j <= N; j++) {
      t = p[j];                                 //ローテーションの右端
      for (k = j; k > i; k--) p[k] = p[k - 1];  //左の要素を右へ移動
      p[i] = t;
      perm(i + 1);
      // t = p[i]; 42行よりt == p[i]だから必要ない
      for (k = i; k < j; k++) p[k] = p[k + 1];
      p[j] = t;
    }
  } else {
    for (j = 1; j < N; j++) printf("%c", p[j]);  //順列の表示
    printf("\n");
  }
}