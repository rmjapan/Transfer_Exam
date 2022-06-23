/**
*    created by: shosei
*    2022.05.09. 10:09:51
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define M 11 //値の取りうる最大値+1
#define N 7

int data[N] = {8, 10, 0, 10, 6, 5, 2};

void f(){
  int i, j, k, B[M];
  for(k=0; k<M; k++)
    B[k]=0;
  for(i = 0; i<N; i++)
    B[data[i]]++;

  i = 0;
  for(k=0; k< M; k++){
    while(B[k]--) data[i++] = k;
  }
}

void print_data(){
  for(int i = 0; i<N; i++)
    printf("%d, ", data[i]);
  printf("\n");
}

int main()
{
  f();
  print_data();
  return 0;
}