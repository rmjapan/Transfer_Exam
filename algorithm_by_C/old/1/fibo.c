#include <stdio.h>

void calc_fibo(int n,int f[]){
  f[0] = f[1] = 1;
  for (int i = 2; i < n; i++){
    f[i] = f[i - 1] + f[i - 2];
  }
}

int main()
{
  int f[100];
  int n = 10;
  calc_fibo(n, f);
  for (int i = 0; i < n; i++)
    printf("%d, ", f[i]);
  printf("\n");
  return 0;
}
