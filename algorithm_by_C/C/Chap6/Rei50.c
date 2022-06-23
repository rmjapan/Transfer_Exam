/*
 * ---------------------------------------
 *      質疑応答と決定木（配列表現）     *
 * ---------------------------------------
 */

#include <stdio.h>

#define Max 100
#define nil -1

int getch(void) {
  rewind(stdin);
  return getchar();
}

void main(void) {
  struct tnode {
    int left;  // 左へのポインタ
    char node[30];
    int right;  // 右へのポインタ
  };
  static struct tnode a[Max] = {
      {1, "芸能人ですか", 2},   {3, "歌手ですか", 4}, {nil, "吉田　茂", nil},
      {nil, "井上　陽水", nil}, {5, "女優ですか", 6}, {nil, "中山　美穂", nil},
      {nil, "久米 宏", nil}};
  int p, lp = 6, c;

  do {
    p = 0;
    while (a[p].left != nil) {  // 木のサーチ
      printf("\n%s y/n ", a[p].node);
      c = getch();
      if (c == 'y' || c == 'Y')
        p = a[p].left;
      else
        p = a[p].right;
    }

    printf("\n答えは %s です。\n正しいですか y/n ", a[p].node);
    c = getch();

    if (c == 'n' || c == 'N') {  // 学習
      a[lp + 1] = a[p];          // ノードの移動
                                 // 新しいノードの作成
      printf("\nあなたの考えは ? ");
      scanf("%s", a[lp + 2].node);
      a[lp + 2].left = a[lp + 2].right = nil;
      // 質問ノードの作成
      printf("%s と %s を区別する質問は ? ", a[lp + 1].node, a[lp + 2].node);
      scanf("%s", a[p].node);
      printf("ｙｅｓの項目は %s で良いですか y/n ", a[lp + 1].node);
      c = getch();

      if (c == 'Y' || c == 'y') {  // 子の接続
        a[p].left = lp + 1;
        a[p].right = lp + 2;
      } else {
        a[p].left = lp + 2;
        a[p].right = lp + 1;
      }
      lp = lp + 2;
    }
  } while (printf("\n続けますか y/n "), c = getch(), c == 'y' || c == 'Y');
  printf("\n");
}
