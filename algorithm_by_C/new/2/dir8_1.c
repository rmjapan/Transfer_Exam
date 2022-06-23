/**
*    author:  shosei
*    created: 29.01.2022 17:26:16
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

#define N 1000 //乱数の発生回数
#define M 10 //整数乱数の範囲
#define F (N/M) //期待値
#define SCALE (40.0/F) //ヒストグラムの高さ

unsigned rndnum = 13;

unsigned irnd();
double rnd();

int main()
{
  int i, j, rank, hist[M + 1];
  double e = 0.0;

  for (i = 1; i <= M; i++)
    hist[i] = 0;

  for (i = 0; i < N; i++){
    rank = (int)(M * rnd() + 1); //1～Mの乱数を一つ発生
    hist[rank]++;
  }

  for (i = 1; i <= M; i++){
    printf("%3d:%3d ", i, hist[i]);
    for (j = 0; j < hist[i] * SCALE; j++){ //実際のiの出現頻度h[i]を期待値Fで割って40.0でスケールを調整している
      printf("*");
    }
    printf("\n");

    e = e + (double)(hist[i] - F) * (hist[i] - F) / F;
  }
  printf("χ2=%f\n", e);

  return 0;
}

unsigned irnd(){
  rndnum = (109 * rndnum + 1021) % 32768;
  return rndnum;
}

double rnd(){ //0～1未満の実数乱数
  return irnd() / 32767.1;
}