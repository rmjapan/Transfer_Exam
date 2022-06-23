#include <stdio.h>
#define Xsize 6
#define Ysize 7
//コピペしてそのまま実機できます。
///プログラムの動きを理解するために、盤面の状態遷移を可視化しています。
///参考に使って見てください。
void LCS(void) {
  char x[Xsize] = {'A', 'B', 'C', 'D', 'E', 'F'};       // 行
  char y[Ysize] = {'A', 'E', 'D', 'C', 'G', 'D', 'F'};  //列
  int LS[Xsize + 1][Ysize + 1];
  for (int i = 0; i < Xsize + 1; i++) {
    LS[i][0] = 0;
  }
  for (int i = 0; i < Ysize + 1; i++) {
    LS[0][i] = 0;
  }
  int i;
  for (i = 1; i < Xsize + 1; i++) {
    for (int j = 1; j < Ysize + 1; j++) {
      LS[i][j] = 0;
    }
  }
  printf("X:");

  for (int i = 0; i < Ysize; i++) {
    printf("%c|", y[i]);
  }
  printf("\n");

  for (i = 1; i < Xsize + 1; i++) {
    printf("%c|", x[i - 1]);
    for (int j = 1; j < Ysize + 1; j++) {
      printf("%d|", LS[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  for (i = 1; i < Xsize + 1; i++) {
    for (int j = 1; j < Ysize + 1; j++) {
      if (x[i - 1] == y[j - 1])
        LS[i][j] = LS[i - 1][j - 1] + 1;
      else if (LS[i - 1][j] > LS[i][j - 1])
        LS[i][j] = LS[i - 1][j];
      else
        LS[i][j] = LS[i][j - 1];
      printf("X:");

      for (int t = 0; t < Ysize; t++) {
        printf("%c|", y[t]);
      }
      printf("\n");
      for (int h = 1; h < Xsize + 1; h++) {
        printf("%c|", x[h - 1]);
        for (int o = 1; o < Ysize + 1; o++) {
          printf("%d|", LS[h][o]);
        }
        printf("\n");
      }
      printf("\n");
    }
  }
  printf("最終結果\n");
  printf("X:");

  for (int i = 0; i < Ysize; i++) {
    printf("%c|", y[i]);
  }
  printf("\n");
  for (i = 1; i < Xsize + 1; i++) {
    printf("%c|", x[i - 1]);
    for (int j = 1; j < Ysize + 1; j++) {
      printf("%d|", LS[i][j]);
    }
    printf("\n");
  }
}

int main(void) { LCS(); }