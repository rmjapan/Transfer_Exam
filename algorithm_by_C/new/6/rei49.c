/**
 *    author:  shosei
 *    created: 20.02.2022 22:17:00
 **/
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
  char ope;
  struct tnode *right;
};

struct tnode *talloc();
struct tnode *gentree(struct tnode *, char *);
void prefix(struct tnode *);
void infix(struct tnode *);
void postfix(struct tnode *);

int main() {
  struct tnode *root;
  char expression[] = "ab*cd+e/-";

  root = NULL;
  root = gentree(root, expression);

  printf("prefix  = ");
  prefix(root);
  printf("\ninfix   = ");
  infix(root);
  printf("\npostfix = ");
  postfix(root);
  printf("\n");
  return 0;
}

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *gentree(struct tnode *p, char *w) {
  int n;
  n = strlen(w);
  p = talloc();
  p->ope = w[n - 1];
  w[n - 1] = '\0';  //終端を除く
  if (!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {
    p->left = p->right = NULL;  //オペランドの時
  } else {
    p->right = gentree(p->right, w);
    p->left = gentree(p->left, w);
  }
  return p;
}

void prefix(struct tnode *p) {
  if (p != NULL) {
    printf("%c", p->ope);
    prefix(p->left);
    prefix(p->right);
  }
}

void infix(struct tnode *p) {
  if (p != NULL) {
    prefix(p->left);
    printf("%c", p->ope);
    prefix(p->right);
  }
}

void postfix(struct tnode *p) {
  if (p != NULL) {
    prefix(p->left);
    prefix(p->right);
    printf("%c", p->ope);
  }
}
