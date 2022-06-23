/**
 *    author:  shosei
 *    created: 16.02.2022 22:41:58
 **/
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

double v[50];  //計算用スタック
char ope[50];  //演算子用スタック
int pri[256];
int sp1, sp2;  //スタックポインタ

void make_pri() {
  pri[0] = -1;  //番兵
  pri['('] = 3;
  pri[')'] = 0;
  pri['|'] = 1;
  pri['<'] = pri['>'] = 2;
}

void calc() {
  switch (ope[sp1]) {
    case '|':
      v[sp2 - 1] = (v[sp2 - 1] + v[sp2]) / 2;
      break;
    case '<':
      v[sp2 - 1] = min(v[sp2 - 1], v[sp2]);
      break;
    case '>':
      v[sp2 - 1] = max(v[sp2 - 1], v[sp2]);
      break;
    default:
      exit(-1);
      break;
  }
  sp2--;
  sp1--;
}

int main() {
  char *expression = "(1>2|2<8|3<4)|(9<2)", *p = expression;
  make_pri();

  ope[0] = 0;
  sp1 = sp2 = 0;
  while (*p != '\0') {
    if (isdigit(*p)) {
      v[++sp2] = *p - '0';
    } else {
      while (pri[*p] <= pri[ope[sp1]] && ope[sp1] != '(') calc();
      if (*p != ')')
        ope[++sp1] = *p;
      else
        sp1--;
    }
    p++;
  }
  while (sp1 > 0) calc();
  printf("%s = %f\n", expression, v[1]);
  return 0;
}