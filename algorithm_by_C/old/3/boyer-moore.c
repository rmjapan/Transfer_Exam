#include <stdio.h>
#include <string.h>

char *search(char *, char *, char *);
void table(char *);
void replace(char *, char *, char);

int skip[256];

int main()
{
  static char text[] = "This is a pen. That is a pencil.";

  replace(text, "key", "cap");//同じ長さである事
}
void table(char *key)
{
  int k, n;

  n = strlen(key);
  for (k = 0; k <= 255; k++)
    skip[k] = n;
  for (k = 0; k < n - 1; k++) //全部nにした後に文字の先頭からn-1番目までを自身の文字コードに対応したbucketに入れていく
    skip[key[k]] = n - 1 - k;
}

char *search(char *text, char *key, char *rep)
{
  int m, n;
  char *p;

  m = strlen(text);
  n = strlen(key);

  p = text + n - 1; //keyの一番最後に対応するテキストの文字のアドレス
  while (p < text + m)
  {
    if (*p == key[n - 1])
    {
      if (strncmp(p - n + 1, key, n) == 0)
        return p - n + 1;
    }
    p = p + skip[*p];
  }
  return NULL;
}
