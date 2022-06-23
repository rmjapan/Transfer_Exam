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
  struct tnode *q, *w[128];
  int sp = 0;

  q = p;
  while (!(sp == 0 && q == NULL)) {
    while (q != NULL) {
      w[sp++] = q;
      q = q->left;
    }
    sp--;
    printf("%15s\n", w[sp]->name);
    q = w[sp]->right;
  }
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
