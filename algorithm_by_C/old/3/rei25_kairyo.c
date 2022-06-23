/*
 * -------------------
 *      繝上ャ繧ｷ繝･     *
 * -------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize 1000

int hash(char *);

struct tel
{ // 繝・・繧ｿ繝ｻ繝・・繝悶Ν
  char name[12];
  char telnum[12];
  int empty;
} dat[TableSize];

void main(void)
{
  int n;
  char a[12], b[12];
  //
  for (int i = 0; i < TableSize; i++)
    dat[i].empty = 0;
  printf("蜷榊燕 髮ｻ隧ｱ逡ｪ蜿ｷ\n");
  while (scanf("%s %s", a, b) != EOF)
  {
    n = hash(a);
    while (dat[n].empty == 1 && n < TableSize - 1)
      n++;

    if (n < TableSize - 1)
    {
      strcpy(dat[n].name, a);
      strcpy(dat[n].telnum, b);
      dat[n].empty = 1;
    }
    else
    {
      printf("陦ｨ縺後＞縺｣縺ｱ縺・〒縺兔n");
    }
  }

  rewind(stdin);
  printf("讀懃ｴ｢縺吶ｋ繝・・繧ｿ繧貞・蜉帙＠縺ｦ縺上□縺輔＞\n");
  while (scanf("%s", a) != EOF)
  {
    n = hash(a);
    while (strcmp(a, dat[n].name) != 0 && n < TableSize - 1)
      n++;
    if (n < TableSize - 1)
      printf("%15s%15s\n", dat[n].name, dat[n].telnum);
    else
    {
      printf("蟄伜惠縺励↑縺・♀\n");
    }
  }
}
int hash(char *s) // 繝上ャ繧ｷ繝･髢｢謨ｰ
{
  int n;
  n = strlen(s);
  return (s[0] - 'A' + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % ModSize;
}
