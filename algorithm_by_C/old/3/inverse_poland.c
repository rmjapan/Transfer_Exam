/**
*    author:  shosei
*    created: 02.06.2021 21:49:45
*    stack.c
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //譁?蟄励?ｮ蜃ｦ逅?繧定｡後≧髢｢謨ｰ鄒､

typedef long ELEM; //縺薙％縺ｧ縺吶∋縺ｦ縺ｮ螟画峩縺後〒縺阪ｋ
#define STACK_SIZE 100
ELEM stack[STACK_SIZE];
int n;

void error(char *s)
{
  fprintf(stderr, s);
  exit(1);
}

void init()
{
  n = 0;
}

void push(ELEM x)
{
  if (n >= STACK_SIZE)
    error("stack overflow\n");
  stack[n++] = x;
}

ELEM pop()
{
  if (n <= 0)
    error("stack underflow\n");
  return stack[--n];
}

//遨ｺ縺ｪ繧会ｼ蝉ｻ･螟悶ｒ霑斐☆
int empty()
{
  return n == 0;
}

int main()
{
  char c;
  long x, a, b;

  init();
  while ((c = getchar()) != EOF)
  {
    if (isdigit(c))
    {
      x = c - '0';
      push(x);
    }
    else
    {
      switch (c)
      {
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
      case '\n':
        if (!empty())
          printf("遲斐∴縺ｯ%ld縺ｧ縺兔n", pop());
        init();
        break;
      case ' ':
      case '\t':
        break;
      default:
        printf("荳肴ｭ｣縺ｪ蜈･蜉帙′縺ゅｊ縺ｾ縺励◆\n");
        printf("蜈･蜉帙＠逶ｴ縺励※縺上□縺輔＞\n");
        while ((c = getchar()) != EOF && c != '\n')
          ;
        break;
      }
    }
  }
  return 0;
}
