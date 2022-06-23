/**
*    author:  shosei
*    created: 24.05.2021 23:47:23
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define M 10
#define N 5

int main()
{
  int a[] = {2, 4, 5, 7, 8, 10, 15, 20, 30, 40},
      b[] = {6, 11, 25, 33, 35},
      c[M + N];
  int i = 0, j = 0, p = 0;

  while (i < M && j < N)
  {
    if (a[i] > b[j])
    {
      c[p] = b[j];
      j++;
      p++;
    }
    else
    {
      c[p] = a[i];
      i++;
      p++;
    }
  }
  if(i == M){
    for (j = j; j < N;j++)
      c[p] = b[j];
  }else{
    for (i = i; i < M;i++)
      c[p] = a[i];
  }
  //for(i = 0; i<N+M; i++)
  rep(i, M + N)  printf("%d ", c[i]);
  
  return 0;
}
