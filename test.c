/**
 *    created by: shosei
 *    2022.06.03. 13:31:14
 **/
#include <stdio.h>
int f = 100;


double _f(int x){
  return f*x;
}

int main() {
  f = 100;
  printf("%lf\n", _f(100));
  return 0;
}