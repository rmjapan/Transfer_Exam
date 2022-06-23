/*
 * --------------------------
 *      暗号化プログラム    *
 * --------------------------
 */

#include <stdio.h>

void main(void) {
  char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
                  'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
                  'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', ' '};
  char *p, *ango = "ALGORITHM";
  int index;

  p = ango;
  while (*p != '\0') {
    for (index = 0; index < 26; index++)
      if (*p == table[index]) putchar('A' + index);
    p++;
  }
  printf("\n");
}
