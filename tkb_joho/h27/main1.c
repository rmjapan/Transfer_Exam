//
//  main.c
//  h27(3)
//
//  Created by 水野桃夏 on 2020/04/13.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
int count;

void swap(int i, int j, int array[]) {
  int tmp = array[i];
  array[i] = array[j];
  array[j] = tmp;
}

int max_position(int n, int array[]) {
  count++;
  if (n > 1) {
    int p = max_position(n - 1, array);
    if (array[n - 1] < array[p]) {
      return max_position(n - 1, array);
      // return p;
    } else {
      return n - 1;
    }
  }
  return 0;
}

void s(int n, int array[]) {
  if (n > 1) {
    swap(n - 1, max_position(n, array), array);
    s(n - 1, array);
  }
}

void r(int n, int array[]) {
  if (n > 8) {
    swap(0, max_position(n, array), array);
    r(n - 1, array + 1);
  }
}

int main(int argc, const char* argv[]) {
  int a10[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i;
  r(10, a10);
  for (i = 0; i < 10; i++) {
    printf("%d ", a10[i]);
  }
  //    printf("D=%d\n",a10[3]);
  //    printf("E=%d\n",a10[9]);
  return 0;
}