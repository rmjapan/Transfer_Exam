/**
*    author:  shosei
*    created: 19.06.2021 16:57:40
**/

#include <stdio.h>
#include <math.h>

int pri[256];
char stack[50], polish[50];
int sp1, sp2;
double v[50];

void make_polish(char *p)
{
  int i = 0;
  int j;
  //priority縺ｮ菴懈・
  for (i = 0; i <= 255; i++)
    pri[i] = 4;
  pri['+'] = pri['-'] = 1;
  pri['*'] = pri['/'] = 2;
  pri['^'] = 3;
  pri['('] = 100;
  pri[')'] = 0;
  stack[0] = 0;
  pri[0] = -1;

  sp1 = sp2 = 0;
  i = 0;
  while (p[i] != '\0')
  {
    while (pri[p[i]] <= pri[stack[sp1]] && stack[sp1] != '(')
      polish[++sp2] = stack[sp1--];
    if (p[i] != ')')
      stack[++sp1] = p[i];
    else
      sp1--;
    i++;
  }
  for (i = sp1; i > 0; i--)
    polish[++sp2] = stack[i];
}

int calc_polish(){
  sp1 = 0;
  int i;
  for (i = 1; i <= sp2; i++)
  {
    if ('0' <= polish[i] && polish[i] <= '9')
    {
      v[++sp1] = polish[i] - '0';
    }
    else
    {
      switch (polish[i])
      {
      case '+':
        v[sp1 - 1] = v[sp1 - 1] + v[sp1];
        break;
      case '-':
        v[sp1 - 1] = v[sp1 - 1] - v[sp1];
        break;
      case '*':
        v[sp1 - 1] = v[sp1 - 1] * v[sp1];
        break;
      case '/':
        v[sp1 - 1] = v[sp1 - 1] * v[sp1];
        break;
      case '^':
        v[sp1 - 1] = pow(v[sp1 - 1], v[sp1]);
        break;
      }
      sp1--;
    }
  }
}

int main()
{
  char p[] = "(1+2)*(3+4)";
  int i;
  make_polish(p);
  calc_polish();

  printf("%s = %f\n",p, v[1]);
  return 0;
}
