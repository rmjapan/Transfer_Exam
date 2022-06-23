#include<stdio.h>

int main(){
  struct c{
    int x;
    int y;
  }*p;
  struct c a[5] = {{6,1},{8,2}, {10, 3}, {12,4}, {14,5}};

  p = a;
  printf("%d\n", p++->x);
  printf("%d\n", p->y);
  printf("%d\n", ++(p->x));
}