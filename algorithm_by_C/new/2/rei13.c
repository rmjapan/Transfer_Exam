/**
 *    author:  shosei
 *    created: 31.01.2022 16:46:23
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

#define KETA 20
#define N ((KETA - 1) / 4 + 1)  // 20のとき6桁にならないように調整

void ladd(short *, short *, short *);
void lsub(short *, short *, short *);
void print(short *);

int main() {
  short a[N + 2] = {1999, 4444, 7777, 2222, 9999},
              b[N + 2] = {111, 6666, 3333, 8888, 1111}, c[N + 2];

  ladd(a,b,c); print(c);
  lsub(a,b,c); print(c);
  return 0;
}

void ladd(short a[], short b[], short c[]){
  short cy = 0; //carry
  for(int i = N-1; i>=0; i--){
    c[i] = a[i]+b[i]+cy;
    if(c[i]>=10000){
      c[i] -= 10000;
      cy = 1;
    }else{
      cy = 0;
    }
  }
}

void lsub(short a[], short b[], short c[]){
  short brrw = 0;
  for(int i = N-1; i>=0; i--){
    c[i] = a[i] - b[i] - brrw;
    if(c[i] < 0){
      c[i] += 10000;
      brrw = 1;
    }else
      brrw = 0;
  }
}

void print(short c[]) {
  for (int i = 0; i < N; i++) {
    printf("%04d ", c[i]);
  }
  printf("\n");
}