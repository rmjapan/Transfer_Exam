/**
*    author:  shosei
*    created: 04.05.2021 14:11:23
**/
#include <stdio.h>
#define L 1000
#define L1 ((L/4)+1)
#define L2 (L1 + 1)
#define N 450
void printresult(short c[]) // 結果の表示
{
  short i;
  printf("%3d. ", c[0]); // 最上位桁の表示
  for (i = 1; i < L1; i++)
    printf("%04d", c[i]);
  printf("\n");
}
void ladd(short a[], short b[], short c[]) // ロング数＋ロング数
{
  short i, cy = 0;
  for (i = L2; i >= 0; i--)
  {
    c[i] = a[i] + b[i] + cy;
    if (c[i] < 10000)
      cy = 0;
    else
    {
      c[i] = c[i] - 10000;
      cy = 1;
    }
  }
}
void lsub(short a[], short b[], short c[]) // ロング数－ロング数
{
  short i, brrw = 0;
  for (i = L2; i >= 0; i--)
  {
    c[i] = a[i] - b[i] - brrw;
    if (c[i] >= 0)
      brrw = 0;
    else
    {
      c[i] = c[i] + 10000;
      brrw = 1;
    }
  }
}
void ldiv(short a[], short b, short c[]) // ロング数÷ロング数
{
  short i;
  long d, rem = 0;
  for (i = 0; i <= L2; i++)
  {
    d = a[i];
    c[i] = (short)((d + rem) / b);
    rem = ((d + rem) % b) * 10000;
  }
}
void lmul(short a[], short b, short c[]) // ロング数×ショート数
{
  short i;
  long cy = 0, d = 0;
  for (i = N - 1; i >= 0; i--)
  {
    d = a[i];
    c[i] = (d * b + cy) % 10000;
    cy = (d * b + cy) / 10000;
  }
}


int main()
{
  short s[L2 + 2]={0},e[L2 + 2]={0};
  int k;
  s[0] = 1;
  e[0] = 1;
  for (k = 1; k <= N; k++){
    ldiv(e, k, e);
    ladd(s, e, s);
  }
  printresult(s);
  return 0;
}
