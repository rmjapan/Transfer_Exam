/*
 * -------------------------------
 *      順列生成（辞書式順）     *
 * -------------------------------
 */

#include <stdio.h>
#include<stdlib.h>

#define N 4
int p[N + 1];

void perm(int);
void rotate(int,int,int);

void main(void)
{
  int i;

  for (i = 1; i <= N; i++) // 初期設定
    p[i] = i;
  perm(1);
}

void perm(int i)
{
  int j, k, t;

  if (i < N)
  {
    for (j = i; j <= N; j++)
    {
      rotate(i, j, 1);
      perm(i + 1);
      rotate(i, j, 2);
    }
  }
  else
  {
    for (j = 1; j <= N; j++) // 順列の表示
      printf("%d ", p[j]);
    printf("\n");
  }
}
//iからjまでローテーションする
void rotate(int i, int j, int flag){
  int k,t;
  switch(flag){
    case 1: //右回り
      t = p[j];
      for (k = j; k > i; k--)
        p[k] = p[k - 1];
      p[i] = t;
      break;
    case 2:
      t = p[i];
      for (k = i; k < j; k++)
        p[k] = p[k + 1];
      p[j] = t;
      break;
    default:
      exit(1);
  }
}
