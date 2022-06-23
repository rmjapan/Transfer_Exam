/**
 *    created by: shosei
 *    09.05.2022 08:27:43
 **/
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N 100

void f(char x[N]) {
  int i;
  for (i = 0; x[i] != '\0'; i++) {
    if (i > 0 && x[i - 1] == '1' && x[i] == '1')
      putchar('0');
    else
      putchar(x[i]);
  }
  printf("\n");
}

int toInt(char x[N]) {
  int i, num;
  num = 0;
  for (i = 0; x[i] != '\0'; i++) {
    if (x[i] == '1') num += 1;
    if (x[i + 1] != '\0') num <<= 1;
  }
  return num;
}

int count(char x[N]) {
  int i, len, maxlen;
  len = 0;
  maxlen = 0;
  for (i = 0; x[i] != '\0'; i++) {
    if (x[i] == '1')
      len++;
    else
      len = 0;
    if (maxlen < len) maxlen = len;
  }
  return maxlen;
}



int main() {
  f("101110011");
  printf("%d\n", toInt("1101"));
  printf("%d\n", count("1011110011"));
  return 0;
}