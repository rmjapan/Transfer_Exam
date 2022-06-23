#include <stdio.h>

int main()
{
  int a[] = {23, 56, 70, 94, 56, 76, 43, 43, 23, 56, 1, 2, 1, 12, 32, 99, 100};
  int n = sizeof(a) / sizeof(int);
  int i, rank, histo[11];

  for (i = 0; i < 11; i++)
  {
    histo[i] = 0;
  }

  for (i = 0; i < n; i++)
  {
    rank = a[i] / 10;
    if (rank >= 0 && rank <= 10)
    {
      histo[rank]++;
    }
  }

  for (i = 0; i < 11; i++)
  {
    printf("%3d  - : %d\n", i * 10, histo[i]);
  }
  return 0;
}
