/**
 *    created by: shosei
 *    2022.05.12. 19:04:36
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
int g(int x) {
  int y = 0;
  while (x > 0) {
    y += x;
    --x;
  }
  return y;
}

int f(int n){

  if(n<=1) return 1;

  return n+f(n-1);
}

int main() {
  int x, y;
  x = 7;
  y = 8;
  printf("x=%d y=%d g(%d)=%d\n", x, y, x, g(x));
  printf("f(%d)=%d\n", 5, f(5));
  return 0;
}