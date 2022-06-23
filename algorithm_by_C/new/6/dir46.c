/**
 *    author:  shosei
 *    created: 19.02.2022 20:24:36
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct tnode {
  struct tnode *left;
  char name[12];
  struct tnode *right;
};

struct tnode *talloc();
struct tnode *gentree(struct tnode *, char *);
void treewalk(struct tnode *);

int main() {
  char dat[12];
  struct tnode *root;

  root = NULL;
  while (scanf("%s", dat) != EOF) {
    root = gentree(root, dat);
  }
  treewalk(root);
  return 0;
}

void treewalk(struct tnode *p) {
  struct connect {
    struct tnode *node;  //子ノード
    char *parent;        //親の名前
    char direct;         //親の左の子か右の子かを示す
  } q[128], w[128];
  int i, child, n, level;

  //初期値
  child = 1;
  level = 0;
  q[0].node = p;
  q[0].parent = "root";
  q[0].direct = ' ';
  do {
    n = 0;
    printf("level %d :\n", level);
    for (i = 0; i < child; i++) {
      printf("%12s->%c:%12s\n", q[i].parent,q[i].direct, q[i].node->name);  //出力
      if (q[i].node->left != NULL) {
        w[n].node = q[i].node->left;
        w[n].parent = q[i].node->name;
        w[n].direct = 'l';
        n++;
      }
      if (q[i].node->right != NULL) {
        w[n].node = q[i].node->right;
        w[n].parent = q[i].node->name;
        w[n].direct = 'r';
        n++;
      }
    }
    child = n;
    for (i = 0; i < child; i++) q[i] = w[i];
    level++;
  } while (child != 0);
}

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *gentree(struct tnode *p, char *w) {
  if (p == NULL) {
    p = talloc();
    p->left = p->right = NULL;
    strcpy(p->name, w);
  } else if (strcmp(w, p->name) < 0)
    p->left = gentree(p->left, w);
  else
    p->right = gentree(p->right, w);
  return p;
}
