#include <stdio.h>

int func(int m ){
  static int cnt = 0;
  printf("cnt = %d ", ++cnt);
  if(m<=1)
    return 1;
  else
    return m * func(m-1);
}

int main(void){
  int i, n;
  scanf("%d", &n);

  for(i = 1; i<= n; i++)
    printf("func(%d) : %d\n", i, func(i));
  return 0;
}
