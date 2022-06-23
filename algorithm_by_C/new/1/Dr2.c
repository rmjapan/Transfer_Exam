#include <stdio.h>

char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
                'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
                'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '?'};

//暗号化
void f(char *p) {
  int index;
  while (*p != '\0') {
    if ('A' <= *p && *p <= 'Z')
      index = *p - 'A';
    else
      index = 26;
    *p = table[index];
    p++;
  }
}

//複合化
//厳密に言うとfは全単射ではないので，近似的な逆写像を考えるためにf^{-1}(?)＝?と定義する．
void f_inv(char *p) {
  int i;
  while (*p != '\0') {
    for (i = 0; i < 27; i++) {
      if (*p == table[i]) {
        *p = 'A' + i;
        break;
      } else if (*p == '?') {
        *p = '?';
        break;
      }
    }
    p++;
  }
}

int main() {
  char s[] = "KSOIDHEPZ++";
  printf("S=");
  printf("%s\n", s);

  printf("f(S)=");
  f(s);  //実質：s=f(s)となっている．
  printf("%s\n",s);

  //複合化が出来ていれば元の文字列に戻る
  printf("f^-1(f(S))=");
  f_inv(s);
  printf("%s\n", s);

  return 0;
}