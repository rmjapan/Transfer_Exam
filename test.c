/**
 *    created by: shosei
 *    2022.06.03. 13:31:14
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand((unsigned int)time(NULL));

  int r;
  r = rand() % 5 + 1;
  printf("%d", r);
  return 0;
}