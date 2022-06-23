/**
 *    author:  shosei
 *    created: 31.01.2022 17:40:23
 **/
#include <stdio.h>

#define L 1000
#define L1 ((L / 4) + 1)
#define L2 (L1 + 1)
#define N (short)(L / 1.39794 + 1)  //計算する項数

void ladd(short *, short *, short *);
void lsub(short *, short *, short *);
void ldiv(short *, short, short *);
void printresult(short *);

int main() {
  short s[L2 + 2], w[L2 + 2], v[L2 + 2], q[L2 + 2];
  short k;
  for (k = 0; k <= L2; k++) s[k] = w[k] = v[k] = q[k] = 0;
  //マチンの公式
  w[0] = 16 * 5;
  v[0] = 4 * 239;  // 2n-1の-1を表現している
  for (k = 1; k <= N; k++) {
    ldiv(w, 25, w);
    ldiv(v, 239, v);
    ldiv(v, 239, v);
    lsub(w, v, q);
    ldiv(q, 2 * k - 1, q);
    if ((k % 2) != 0)  //奇数効果偶数項か判定
      ladd(s, q, s);
    else
      lsub(s, q, s);
  }
  printresult(s);
  return 0;
}

void ladd(short a[], short b[], short c[]) {
  short cy = 0;  // carry
  for (int i = N - 1; i >= 0; i--) {
    c[i] = a[i] + b[i] + cy;
    if (c[i] >= 10000) {
      c[i] -= 10000;
      cy = 1;
    } else {
      cy = 0;
    }
  }
}

void lsub(short a[], short b[], short c[]) {
  short brrw = 0;
  for (int i = N - 1; i >= 0; i--) {
    c[i] = a[i] - b[i] - brrw;
    if (c[i] < 0) {
      c[i] += 10000;
      brrw = 1;
    } else
      brrw = 0;
  }
}

void ldiv(short a[], short b, short c[]) {
  long d, rem = 0;
  for (int i = 0; i < N; i++) {
    d = a[i];
    c[i] = (short)((d + rem) / b);
    rem = ((d + rem) % b) * 10000;
  }
}

void printresult(short c[])  // 結果の表示
{
  short i;
  printf("%3d. ", c[0]);  // 最上位桁の表示
  for (i = 1; i < L1; i++) printf("%04d ", c[i]);
  printf("\n");
}