/**
 *    author:  shosei
 *    created: 16.02.2022 18:18:24
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

enum sp { s, p };
int sp[2];  //スタックポインタ

int pri[256];
char stack[100], polish[100];

void make_pri() {
  for (int i = 1; i < 256; i++) pri[i] = 3;
  pri[0] = -1;  //番兵
  pri['('] = 0;
  pri['*'] = pri['/'] = 2;
  pri['+'] = pri['-'] = 1;
}

// input:数式
// output:逆Poland記法の数式
void mk_rvs_notation(char a[]) {
  int i = 0;
  stack[sp[s]++] = 0;
  while (a[i] != '\0') {
    if (a[i] == '(')
      stack[sp[s]++] = a[i];
    else if (a[i] == ')') {
      while (stack[sp[s] - 1] != '(') polish[sp[p]++] = stack[--sp[s]];
      sp[s]--;  //残った'('を捨てる
    } else {
      while (pri[a[i]] <= pri[stack[sp[s] - 1]])
        polish[sp[p]++] = stack[--sp[s]];
      stack[sp[s]++] = a[i];
    }
    i++;
  }

  for (i = sp[s] - 1; i > 0; i--) {
    polish[sp[p]++] = stack[i];
  }
}

int main() {
  char input[100];
  make_pri();
  scanf("%s", input);
  mk_rvs_notation(input);
  for (int i = 0; i < sp[p]; i++) putchar(polish[i]);
  printf("\n");
  return 0;
}