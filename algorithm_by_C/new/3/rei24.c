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

int skip[256];

void table(char *key) {
  int k, n;
  n = strlen(key);
  for (k = 0; k <= 255; k++) skip[k] = n;  // nで初期化
  for (k = 0; k < n - 1; k++)  //最後の文字はnのままで良いから含めない
    skip[key[k]] = n - 1 - k;  //同じ文字が来ても自動的に小さいほうになる
}

char *search(char *text, char *key) {
  char *p;
  int m, n;
  m = strlen(text);
  n = strlen(key);
  p = text;
  while (p < text + m) {
    if (*p == key[n - 1]) {
      if (strncmp(p - n + 1, key, n) == 0) return p - n + 1;
    }
    p = p + skip[*p];
  }
  return NULL;
}

void replace(char *text, char *key, char *rep) {
  char *p;
  int n;
  p = search(text, key);
  n = strlen(rep);
  while (p != NULL) {
    for (int i = 0; i < n; i++) p[i] = rep[i];
    p = search(p + strlen(key), key);
  }
}

int main() {
  static char text[] = "This is a pen. That is a pencil.";
  char *key = "pen", *rep = "cap";

  table(key);
  replace(text, key, rep);
  printf("%s\n", text);
  return 0;
}