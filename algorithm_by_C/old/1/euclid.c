#include <stdio.h>

int GCD(int n, int m){
  int k;
  do{
    k = m % n;
    m = n;
    n = k;
  } while (n != 0);
  return m;
}

int main()
{
  int a, b;
  scanf("%d %d", &a, &b);

  printf("GCD(%d, %d) = %d\n", a, b, GCD(a, b));
  return 0;
}
