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
  struct tnode *q[128], *w[128];
  int i, child, n, level;

  child = 1;  //子の数
  q[0] = p;
  level = 0;
  do {
    n = 0;
    printf("level %d :", level);
    for (i = 0; i < child; i++) {
      printf("%15s", q[i]->name);  //出力
      if (q[i]->left != NULL)      //子の情報を確保
        w[n++] = q[i]->left;
      if (q[i]->right != NULL) w[n++] = q[i]->right;
    }
    printf("\n");
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
