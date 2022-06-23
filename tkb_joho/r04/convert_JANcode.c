/**
 *    author:  shosei
 *    created: 25.03.2022 18:20:20
 **/
/*プログラムの説明：
バーコードを表すビット列(67桁)を入力とし，対応するJANコード(右側４桁のみ)を生成するプログラム
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// barcode[]の最下位ビットからnビット目(ただしn=0, ...
// ,66)の値を「１」に変更する
void set_bit(unsigned char *, int);
// barcode[]の最下位ビットからnビット目を「0」に変更する
void clear_bit(unsigned char *barcode, int n);
// barcode[]の最下位ビットからnビット目の値を取得する
int get_bit(const unsigned char *barcode, int n);
//バーコードを表す67個のビットデータを受け取り，8桁のJANコードの右からm+1桁目(ただし，m=0,
//..., 3)を出力する．
int recognize_right_character(int, unsigned char *, unsigned int *);

// right_characters[i] = iに対応する右側データキャラクタを得る
// 16進数に変換するのが面倒なので２進数で書いてる．
const unsigned char right_characters[10] = {
    0b1110010, 0b1100110, 0b1101100, 0b1000010, 0b1011100,
    0b1001110, 0b1010000, 0b1000100, 0b1001000, 0b1110100};

int main() {
  unsigned char barcode[9];
  unsigned int jancode[8];

  //バーコードの初期化
  // 2021 9567に対応, これは図３を愚直に写したもの，残骸も一緒に載せています．
  barcode[0] = 0b00100101;
  barcode[1] = 0b01000010;
  barcode[2] = 0b10011101;
  barcode[3] = 0b01110100;
  barcode[4] = 0b10010101;
  barcode[5] = 0b10011001;
  barcode[6] = 0b00110100;
  barcode[7] = 0b00100110;
  barcode[8] = 0b00000101;

  //テスト用, すべて正常に動作
  // set_bit(barcode, 65);
  // clear_bit(barcode, 65);
  // if(get_bit(barcode, 70))
  //   printf("1\n");
  // else
  //   printf("0\n");

  for (int i = 0; i < 4; i++)
    if (!recognize_right_character(i, barcode, jancode)) {
      printf("error\n");
      exit(-1);
    }
  // jancode[0]～jancode[3]を出力
  // 出力：7 6 5 9より,2021 9567 ←右読みとの対応が確かに確認できる．
  for (int i = 0; i < 4; i++) {
    printf("%d ", jancode[i]);
  }
  printf("\n");
  return 0;
}

void set_bit(unsigned char *barcode, int n) {
  *(barcode + (n / 8)) |= (unsigned char)(1 << (n % 8));
}

void clear_bit(unsigned char *barcode, int n) {
  *(barcode + (n / 8)) &= (unsigned char)(~(1 << (n % 8)));
}

int get_bit(const unsigned char *barcode, int n) {
  if (*(barcode + (n / 8)) & (unsigned char)(1 << (n % 8)))
    return 1;
  else
    return 0;
}

int recognize_right_character(int m, unsigned char *barcode,
                              unsigned int *jancode) {
  int i;
  int offset;
  unsigned char number = 0;
  //ライトガードバー3ビットと7ビット区切りのデータキャラクタの分をずらした
  offset = 7 * m + 3;
  for (i = 0; i < 7; i++) {
    if (get_bit(barcode, offset)) {
      // number |= (unsigned char)(1 << i);
      set_bit(&number, i);
    }
    offset++;
  }

  for (i = 0; i < 10; i++) {
    if (number == right_characters[i]) {
      *(jancode + m) = i;
      return 1;
    }
  }
  return 0;
}