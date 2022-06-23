/**
 *    author:  shosei
 *    created: 14.02.2022 17:30:39
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

enum pole {  //棒を管理
  A,
  B,
  C
};

void hanoi(int, int, int, int);

void move(int, int, int);

int pie[20][3];
int sp[3], N;

int main() {
  int i;
  printf("Number of disk:");
  scanf("%d", &N);

  rep(i, N) pie[i][A] = N - i;  //棒aに円盤を積む
  sp[A] = N;
  sp[B] = sp[C] = 0;
  hanoi(N, 0, 1, 2);
  return 0;
}

void hanoi(int n, int a, int b, int c) {
  if (n > 0) {
    hanoi(n - 1, a, c, b);
    move(n, a, b);
    hanoi(n - 1, c, b, a);
  }
}

void move(int n, int s, int d) {
  int i, j;

  pie[sp[d]][d] = pie[sp[s] - 1][s];  // s->dへの円盤の移動
  sp[d]++;
  sp[s]--;

  printf("move %d from %c to %c\n", n, 'a' + s, 'a' + d);
  for (i = N - 1; i >= 0; i--) {
    for (j = 0; j < 3; j++) {
      if (i < sp[j])
        printf("%8d", pie[i][j]);
      else
        printf("        ");
    }
    if (i != 0) printf("\n");
  }
  printf("\n       a       b       c\n");
  rewind(stdin);
  getchar();
}