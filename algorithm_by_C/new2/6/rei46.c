/*
 * -----------------------------------------------
 *      レベルごとの２分探索木のトラバーサル     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
  struct tnode *left;   // 左部分木へのポインタ
  char name[12];        // 名前
  struct tnode *right;  // 右部分木へのポインタ
};

struct tqueue {
  struct tnode *node;
  int depth;
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);
void treewalk(struct tnode *);

void main(void) {
  char dat[12];
  struct tnode *root;

  root = NULL;
  while (scanf("%s", dat) != EOF) {
    root = gentree(root, dat);
  }
  treewalk(root);
  printf("\n");
}
void treewalk(struct tnode *p)  // レベルごとの木のトラバーサル
{
  struct tnode *q;
  struct tqueue que[128];
  int head = 0, tail = 0;
  int depth;           //現在の深さ
  int pre_depth = -1;  //ひとつ前の深さ

  que[tail].node = p;
  que[tail].depth = 0;
  tail++;
  do {
    pre_depth = depth;
    q = que[head].node;
    depth = que[head].depth;
    head++;
    if (pre_depth != depth) {
      printf("\n");
      printf("level %d : %12s", depth, q->name);
    } else  //深さが同じときは名前だけ出力
      printf("%12s", q->name);

    if (q->left != NULL) {
      que[tail].node = q->left;
      que[tail].depth = depth + 1;
      tail++;
    }

    if (q->right != NULL) {
      que[tail].node = q->right;
      que[tail].depth = depth + 1;
      tail++;
    }

  } while (head != tail);
  printf("\n");
}
struct tnode *gentree(struct tnode *p, char *w)  // 木の作成の再帰手続き
{
  if (p == NULL) {
    p = talloc();
    strcpy(p->name, w);
    p->left = p->right = NULL;
  } else if (strcmp(w, p->name) < 0)
    p->left = gentree(p->left, w);
  else
    p->right = gentree(p->right, w);
  return p;
}
struct tnode *talloc(void)  // 記憶領域の取得
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}
