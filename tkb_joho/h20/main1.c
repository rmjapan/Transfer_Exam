//
//  main.c
//  h20(3)
//
//  Created by 水野桃夏 on 2020/04/19.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
int iseven(int n) { return n % 2 == 0 ? 1 : 0; }
int square(int n) { return n * n; }
int halve(int n) { return n / 2; }

int func(int b, int n) {
  if (n == 0)
    return 1;
  else
    return b * func(b, n - 1);
}

int func1(int b, int n) {
  if (n == 0)
    return 1;
  else if (iseven(n))
    return func1(square(b), halve(n));
  else
    return b * func1(b, n - 1);
}

int func2(int b, int n) {
  if (n == 0)
    return 1;
  else if (iseven(n))
    return func2(square(b), halve(n));
  else
    return b * func2(square(b), halve(n - 1));
}

int main() {
  printf("%d\n", func2(2, 10));
  return 0;
}