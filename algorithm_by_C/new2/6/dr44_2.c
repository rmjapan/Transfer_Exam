/**
 *    created by: shosei
 *    2022.06.20. 12:04:14
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

struct tnode {
  struct tnode *left;
  char name[12];
  struct tnode *right;
};

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

void gentree(struct tnode **p, char *w)  // 木の作成の再帰手続き
{
  struct tnode *q;
  q = *p;  // qが*pを指しても，pはqを指していない
  if (q == NULL) {
    q = talloc();
    strcpy(q->name, w);
    q->left = q->right = NULL;
    *p = q;
  } else if (strcmp(w, q->name) < 0)
    gentree(&(q->left), w);
  else
    gentree(&(q->right), w);
}

int main() {
  char dat[12], key[12];
  struct tnode *root, *p;

  root = NULL;
  while (scanf("%s", dat) != EOF) {
    gentree(&root, dat);
  }

  p = root;
  while (p != NULL) {
    printf("%s\n", p->name);
    p = p->left;
  }
  return 0;
}