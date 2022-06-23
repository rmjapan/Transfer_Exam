/**
*    author:  shosei
*    created: 04.05.2021 14:56:08
**/
#include <stdio.h>
void ladd(short *, short *, short *);
void lsub(short *, short *, short *);
void ldiv(short *, short, short *);
void lmul(short *, short, short *);
void printresult(short *);

#define L 64             // 求める桁数
#define N 49             //n! のN
#define L2 ((L + 3) / 4) // 配列のサイズ
int main()
{
  short s[L2];
  short k;

  for (k = 1; k < L2; k++)
    s[k] = 0;

  s[L2 - 1] = 1; //0!
  for (k = 1; k <= 49; k++)
  {
    lmul(s, k, s);
    printf("%2d!=", k);
    printresult(s);
  }

  return 0;
}

void printresult(short c[]) // 結果の表示
{
  short i;
  for (i = 1; i < L2; i++)
    printf("%04d", c[i]);
  printf("\n");
}
void lmul(short a[], short b, short c[]) // ロング数×ショート数
{
  short i;
  long cy = 0, d = 0;
  for (i = L2 - 1; i >= 0; i--)
  {
    d = a[i];
    c[i] = (d * b + cy) % 10000;
    cy = (d * b + cy) / 10000;
  }
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
