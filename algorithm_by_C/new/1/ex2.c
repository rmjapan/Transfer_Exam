/**
 *    author:  shosei
 *    created: 14.01.2022 21:48:13
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int histo[11];
int main()
{
  int a[] = {35, 25, 56, 78, 43, 66, 71, 73, 80, 90,
             0, 73, 35, 65, 100, 78, 80, 85, 35, 50};
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  {
    int rank;
    rank = a[i] / 10;
    if (0 <= rank && rank <= 10)
      histo[rank]++;
  }
  for (int i = 0; i < 11; i++)
  {
    printf("%3d -  :  %d\n", i * 10, histo[i]);
  }

  return 0;
}