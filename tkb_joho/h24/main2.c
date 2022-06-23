#include <stdio.h>
#include <string.h>

int count = 0;

int proc(char *text, char *ptn) {
  int i = 0, j = 0;
  int m, n;
  n = strlen(text);
  m = strlen(ptn);

  while (i < n)
    if (count++, text[i] == ptn[j]) {
      if (j == m - 1)
        return i - m + 1;
      else {
        i++;
        j++;
      }
    } else {
      i = i - j + 1;
      j = 0;
    }
  return -1;
}

void main() {
  char text[] = "CCACCACBCC";
  char ptn[] = "CACB";
  printf("Result: %d ", proc(text, ptn));
  printf("回数: %d\n", count);
}