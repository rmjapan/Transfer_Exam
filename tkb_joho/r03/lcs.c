/**
 *    author:  shosei
 *    created: 07.07.2021 23:46:16
 **/

#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b)) ? (a) : (b)

int mat[100][100];
void printer(int len1, int len2) {
  int i, j;
  for (i = 0; i <= len1; i++) {
    for (j = 0; j <= len2; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  char str1[] = "ABCDEF";
  char str2[] = "AEDCAGDF";
  //エラー対策でunsignedから変更，符号なしだと負の値が出てきたとき（55行目:k），バカでかい値になっていまう
  int i, j, k;
  unsigned int len1 = strlen(str1);
  unsigned int len2 = strlen(str2);
  unsigned int row = len1, col = len2;
  char res1[] = "CBCDEF", res2[] = "AEDCAGDF";

  for (i = 0; i <= len1; i++) mat[i][0] = 0;
  for (j = 0; j <= len2; j++) mat[0][j] = 0;

  // dpテーブル生成
  for (i = 1; i <= len1; i++) {
    for (j = 1; j <= len2; j++) {
      //文字列の先頭str1[0]とmat[0][1]が対応するため，ズレがある
      char nextchar1 = str1[i - 1];
      char nextchar2 = str2[j - 1];
      if (nextchar1 == nextchar2) {
        mat[i][j] = mat[i - 1][j - 1] + 1;  //左上の値を使って更新
        printer(len1, len2);
      } else {
        // 左もしくは上の値を使って更新
        mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
        printer(len1, len2);
      }
    }
  }
  printer(len1, len2);
  printf("len(LCS): %d\n", mat[len1][len2]);  //最長共通部分列の長さ

  while (1) {
    if (col == 0 && row == 0) break;  //これないとなんかエラーでる．
    if (col == 0) {
      for (k = row - 1; k >= 0; k--) {
        res1[k] = '-';
      }
      break;
    }

    if (row == 0) {
      for (k = col - 1; k >= 0; k--) {
        res2[k] = '-';
      }
      break;
    }

    if (mat[row][col] == mat[row - 1][col]) {
      row--;
      res1[row] = '-';
    } else if (mat[row][col] == mat[row][col - 1]) {
      col--;
      res2[col] = '-';
    } else if (mat[row][col] == mat[row - 1][col - 1] + 1) {
      col--;  //ズレの調整
      row--;
      res1[row] = str1[row];  //角に来た時
      res2[col] = str2[col];
    }
  }
  printf("Selected characters 1 : %s\n", res1);
  printf("Selected characters 2 : %s\n", res2);

  return 0;
}