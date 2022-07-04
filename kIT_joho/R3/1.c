#include<stdio.h>

void func(int v, int *q){
  v++;
  (*q)++;
}

int main(){
  int x = 0, y = 1, z = 2;
  int *p;
  p = &x;
  (*p)++;
  func(x, &y);
  z += y++;
  printf("x = %d y = %d z = %d\n", x, y, z);
  return 0;
}