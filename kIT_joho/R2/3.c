/**
*    created by: shosei
*    2022.05.12. 19:14:35
**/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int main()
{
  char *p;
  char s[] = "cde";
  p = s;
  while(*p != '\0'){
    printf("%p\n", p);
    *p += 1; //文字をずらしている．ex)a→b
    p++;

  }
  printf("%p\n", p);
  // printf("s: %s\n", s);
  return 0;
}