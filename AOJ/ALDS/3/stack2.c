/**
 *    author:  shosei
 *    created: 08.02.2022 03:19:12
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

#define STACK_SIZE 100

int stack[STACK_SIZE];
int sp = 0;

void push(int n) {
  if (sp > STACK_SIZE) {
    printf("スタックが満タンだお\n");
    exit(1);
  }
  stack[sp++] = n;
}

int pop() {
  if (sp == 0) {
    printf("スタックが空だお\n");
    exit(1);
  }
  return stack[--sp];
}
//スタックが空なら1、そうでなければ０
int empty() { return (sp == 0); }

int main() {
  char op[10];
  int a, b;
  while (scanf("%s", op) != EOF) {
    if (isdigit(op[0])) {
      push(atoi(op));
    } else {
      switch (op[0]) {
        case '+':
          b = pop();
          a = pop();
          push(a + b);
          break;
        case '-':
          b = pop();
          a = pop();
          push(a - b);
          break;
        case '*':
          b = pop();
          a = pop();
          push(a * b);
          break;
        case '/':
          b = pop();
          a = pop();
          push(a / b);
          break;
        case ' ':
        case '\t':
          break;
        default:
          break;
      }
    }
  }
  if (!empty()) printf("%d\n", pop());
  return 0;
}