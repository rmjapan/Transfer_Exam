/**
 *    author:  shosei
 *    created: 06.02.2022 18:39:24
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

char *search(char *text, char *key) {
  int m, n;
  char *p;  //見つかった位置のポインタ
  m = strlen(text);
  n = strlen(key);
  for (p = text; p <= text + m - n; p++) {
    if ((p == text || *(p - 1) == ' ' || *(p - 1) == '.' || *(p + n) == ',') &&
        strncmp(p, key, n) == 0 &&
        (*(p + n) == ' ' || *(p + n) == '.' || *(p + n) == '\0' ||
         *(p + n) == ','))
      return p;
  }
  return NULL;
}

int main() {
  static char text[] = "This is a pen, That is a pencil.";
  char *p, *key = "pen";

  p = search(text, key);
  while (p != NULL) {
    printf("%s\n", p);
    p = search(p + strlen(key), key);
  }
  return 0;
}