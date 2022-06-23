/**
 *    author:  shosei
 *    created: 08.02.2022 20:00:58
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define Total 'a' + 'b' + 'c'

void swap(int *a, int *b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
// n:円盤の数
void hanoi(int n, char a, char b) {
  if (n > 0) {
    hanoi(n - 1, a, Total - (a + b));
    printf("move %d from %c to %c\n", n, a, b);
    hanoi(n - 1, Total - (a + b), b);
  }
}

int main() {
  int n;
  printf("円盤の枚数:");
  scanf("%d", &n);
  hanoi(n, 'a', 'b');
  return 0;
}