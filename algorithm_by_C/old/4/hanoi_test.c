#include <stdio.h>
#define N 5 //谿ｵ謨ｰ
#define Total 'a' + 'b' + 'c'

void mov()
int hanoi(int n, char a, char b)
{
  int static count = 0;
  if (n > 0)
  {
    hanoi(n - 1, a, Total - (a + b));
    mov();
    count++;
    hanoi(n - 1, Total - (a + b), b);
  }
  return count;
}

void main()
{
  int ans = hanoi(N, 'a', 'b');
  printf("%d", ans);
}
