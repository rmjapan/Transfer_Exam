/**
*    author:  shosei
*    created: 02.06.2021 23:24:03
**/
#include <stdio.h>
#include <string.h>
#define MODSIZE 1000
#define TABLE_SIZE 1000

struct tel
{
  char name[20];
  char telnum[20];
} dat[TABLE_SIZE];

int hash(char *s)
{
  int n;
  n = strlen(s);
  return ((s[0] - 'A') + (s[n / 2 - 1] - 'A') * 26 + (s[n - 2] - 'A') * 26 * 26) % MODSIZE;
}

int main()
{
  int n;
  char a[20], b[20];
  printf("蜷榊燕縲髮ｻ隧ｱ逡ｪ蜿ｷ\n");
  while (scanf("%s %s", a, b) != EOF)
  {
    n = hash(a);
    strcpy(dat[n].name, a);
    strcpy(dat[n].telnum, b);
  }
  rewind(stdin);
  printf("讀懃ｴ｢縺吶ｋ繝・・繧ｿ繧貞・蜉帙＠縺ｦ縺上□縺輔＞\n");
  while (scanf("%s", a) != EOF)
  {
    n = hash(a);
    printf("%15s%15s\n", dat[n].name, dat[n].telnum);
  }

  return 0;
}
