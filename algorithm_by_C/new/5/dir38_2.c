/**
 *    author:  shosei
 *    created: 16.02.2022 18:18:24
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

enum sp { S, P, V };
int sp[3];  //スタックポインタ

int pri[256];
char stack[100], polish[100];
double v[100];  //計算用スタック

void make_pri() {
  for (int i = 0; i < 256; i++) pri[i] = 4;
  pri[0] = -1;  //番兵
  pri['('] = 5;
  pri[')'] = 0;
  pri['^'] = 3;
  pri['*'] = pri['/'] = 2;
  pri['+'] = pri['-'] = 1;
}

void print_stack() {
  static int cnt = 1;
  printf("%d\n", cnt++);
  printf("polish: ");
  for (int i = 0; i < sp[P]; i++) {
    putchar(polish[i]);
  }
  printf("\nstack: ");
  for (int i = 0; i < sp[S]; i++) {
    putchar(stack[i]);
  }
  printf("\n\n");
}

void print_v() {
  static int cnt = 1;
  printf("%d\n", cnt++);
  printf("v: ");
  for (int i = 0; i < sp[V]; i++) {
    printf("%.2f ", v[i]);
  }
  printf("\n\n");
}

void mk_rvs_notation(char a[]) {
  int i = 0;
  stack[sp[S]++] = 0;
  while (a[i] != '\0') {
    while (pri[a[i]] <= pri[stack[sp[S] - 1]] &&
           stack[sp[S] - 1] != '(')  //スタックトップが(なら取り出しを行わない
      polish[sp[P]++] = stack[--sp[S]];
    if (a[i] != ')')
      stack[sp[S]++] = a[i];
    else
      sp[S]--;
    i++;
    // print_stack();
  }

  for (i = sp[S] - 1; i > 0; i--) {
    polish[sp[P]++] = stack[i];
  }
}

double calc_polish() {
  double a, b;
  for (int i = 0; i < sp[P]; i++) {
    if (isdigit(polish[i])) {
      v[sp[V]++] = polish[i] - '0';
    } else {
      switch (polish[i]) {
        case '+':
          b = v[--sp[V]];
          a = v[--sp[V]];
          v[sp[V]++] = a + b;
          break;
        case '-':
          b = v[--sp[V]];
          a = v[--sp[V]];
          v[sp[V]++] = a - b;
          break;
        case '*':
          b = v[--sp[V]];
          a = v[--sp[V]];
          v[sp[V]++] = a * b;
          break;
        case '/':
          b = v[--sp[V]];
          a = v[--sp[V]];
          v[sp[V]++] = a / b;
          break;
        case '^':
          b = v[--sp[V]];
          a = v[--sp[V]];
          v[sp[V]++] = pow(a, b);
          break;
        default:
          printf("This command is not exit\n");
          exit(-1);
          break;
      }
    }
    print_v();
  }
  return v[0];
}

int main() {
  char input[100];
  make_pri();
  scanf("%s", input);
  mk_rvs_notation(input);
  for (int i = 0; i < sp[P]; i++) putchar(polish[i]);
  printf("%lf\n", calc_polish());
  return 0;
}