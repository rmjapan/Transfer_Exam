/*
 * -------------------------------------------
 *      木（動的表現）のディスクへの保存     *
 * -------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define Rec 34L  // レコード・サイズ
#define Leaf -1  // 葉
FILE *fp;

struct tnode {
  struct tnode *left;  // 左の子へのポインタ
  char node[30];
  struct tnode *right;  // 右の子へのポインタ
};

struct tnode *talloc(void);
struct tnode *readtree(struct tnode *);
void writetree(struct tnode *);

int getch(void) {
  rewind(stdin);
  return getchar();
}

void main(void) {
  struct tnode *root = NULL, *p, *q1, *q2;
  int c;

  if ((fp = fopen("dbase.dat", "r")) == NULL) {
    root = talloc();
    printf("初期ノード ? ");
    scanf("%s", root->node);
    root->left = root->right = NULL;
  } else {
    root = readtree(root);
    fclose(fp);
  }
  do {
    p = root;  // 木のサーチ
    while (p->left != NULL) {
      printf("\n%s y/n ", p->node);
      c = getch();
      if (c == 'Y' || c == 'y')
        p = p->left;
      else
        p = p->right;
    }

    printf("\n答えは %s です。\n正しいですか y/n ", p->node);
    c = getch();

    if (c == 'n' || c == 'N') {  // 学習
      q1 = talloc();
      *q1 = *p;  // ノードの移動

      q2 = talloc();  // 新しいノードの作成
      printf("\nあなたの考えは ? ");
      scanf("%s", q2->node);
      q2->left = q2->right = NULL;
      // 質問ノードの作成
      printf("%s と %s を区別する質問は ? ", q1->node, q2->node);
      scanf("%s", p->node);
      printf("ｙｅｓの項目は %s で良いですか y/n ", q1->node);
      c = getch();
      if (c == 'Y' || c == 'y') {  // 子の接続
        p->left = q1;
        p->right = q2;
      } else {
        p->left = q2;
        p->right = q1;
      }
    }
  } while (printf("\n続けますか y/n "), c = getch(), c == 'Y' || c == 'y');
  printf("\n");
  if ((fp = fopen("dbase.dat", "w")) != NULL) {
    writetree(root);
    fclose(fp);
  }
}
struct tnode *readtree(struct tnode *p)  // ファイルから木をリード
{
  int flag;

  p = talloc();
  fscanf(fp, "%30s%4d", p->node, &flag);
  if (flag == Leaf)
    p->left = p->right = NULL;
  else {
    p->left = readtree(p->left);
    p->right = readtree(p->right);
  }
  return p;
}
void writetree(struct tnode *p)  // ファイルに木をライト
{
  if (p != NULL) {
    if (p->left == NULL)
      fprintf(fp, "%30s%4d", p->node, Leaf);
    else
      fprintf(fp, "%30s%4d", p->node, !Leaf);
    writetree(p->left);
    writetree(p->right);
  }
}
struct tnode *talloc(void)  // 記憶領域の取得
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}
