#include <stdio.h>

int main(void) {
  int a[][3] = {{1, 2, 3}, {4, 5, 6}};
  printf("%d\n%d\n%d\n", a[0][2], *(*(a + 1) + 1), *a[1]);
}