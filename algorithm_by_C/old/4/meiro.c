/**
*    author:  shosei
*    created: 10.06.2021 19:20:43
**/
#include <stdio.h>
#define PRINT_COUNT 60
int m[9][9] = {{2, 2, 2, 2, 2, 2, 2, 2, 2},
               {2, 0, 0, 0, 0, 0, 0, 0, 2},
               {2, 0, 2, 2, 0, 2, 2, 0, 2},
               {2, 0, 2, 0, 0, 2, 0, 0, 2},
               {2, 0, 2, 0, 2, 0, 2, 0, 2},
               {2, 0, 0, 0, 0, 0, 2, 0, 2},
               {2, 2, 0, 2, 2, 0, 2, 2, 2},
               {2, 0, 0, 0, 0, 0, 0, 0, 2},
               {2, 2, 2, 2, 2, 2, 2, 2, 2}};

int si, sj, ei, ej, success;
int sp, ri[100], rj[100];

int visit(int i, int j);
int print_m(int, int);
int main()
{
  success = 0;
  si = 1;
  sj = 1;
  ei = 7;
  ej = 7;
  sp = 0;
  printf("\n霑ｷ霍ｯ縺ｮ謗｢邏｢\n");
  if (visit(si, sj) == 0)
    printf("蜃ｺ蜿｣縺ｯ隕九▽縺九ｊ縺ｾ縺帙ｓ縺ｧ縺励◆\n");
  printf("\n");
  return 0;
}

int visit(int i, int j)
{
  static int path = 1;
  m[i][j] = 1;
  ri[sp] = i;
  rj[sp] = j;
  sp++;
  print_m(i, j);
  printf("\n");
  if (i == ei && j == ej)
  {
    printf("\npath=%d\n", path++); //螳溯｡後＠縺溷ｾ後↓繧､繝ｳ繧ｯ繝ｪ繝｡繝ｳ繝・
    for (int i = 0; i < sp; i++)
      printf("(%d,%d) ", ri[i], rj[i]);
    success = 1;
  }

  if (m[i][j + 1] == 0)
    visit(i, j + 1);
  if (m[i + 1][j] == 0)
    visit(i + 1, j);
  if (m[i][j - 1] == 0)
    visit(i, j - 1);
  if (m[i - 1][j] == 0)
    visit(i - 1, j);

  sp--;
  m[i][j] = 0; //蛻･縺ｮ邨瑚ｷｯ謗｢邏｢縺ｮ縺溘ａ縺ｫ
  return success;
}

//霑ｷ霍ｯ蜈ｨ髱｢繧定｡ｨ遉ｺ縺励▽縺､蠎ｧ讓・a,b)繧湛縺ｧ陦ｨ縺・
int print_m(int a, int b)
{
  int i, j;
  static int count = 0;
  count++;
  if (count > PRINT_COUNT)
    return 0;

  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      if (i == a && j == b)
        printf("笨・");
      else
        printf("%d ", m[i][j]);
    }
    printf("\n");
  }
  return 0;
}
