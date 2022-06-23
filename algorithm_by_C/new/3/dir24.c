/**
 *    author:  shosei
 *    created: 06.02.2022 19:13:17
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
  char *p;
  int m, n;
  m = strlen(text);
  n = strlen(key);
  for (p = text; p <= text + m - n; p++) {
    if (strncmp(p, key, n) == 0) return p;
  }
  return NULL;
}

void replace(char *text, char *key, char *rep) {
  char *p, buf[128];

  p = search(text, key);
  while (p != NULL) {
    *p = '\0';  // keyの先頭が文字列の終端になっている証
    strcpy(buf, p + strlen(key));
    strcat(text, rep);
    strcat(text, buf);
    p = search(p + strlen(key), key);
  }
}

int main() {
  int k;
  static char text[][128] = {"     --- サルビアの花 ---",
                             "いつもいつも思ってた",
                             "サルビアの花をあなたの部屋の中に",
                             "投げ入れたくて",
                             "そして君のベッドに",
                             "サルビアの紅い花しきつめて",
                             "僕は君を死ぬまで抱きしめていようと",
                             ""};
  char *key, *rep;
  key = "サルビア";
  rep = "か す み 草";

  k = 0;
  while (text[k][0] != '\0') {
    replace(text[k], key, rep);
    replace(text[k], "紅", "白");
    printf("%s\n", text[k]);
    k++;
  }
  return 0;
}