/**
 *    author:  shosei
 *    created: 18.02.2022 22:14:35
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
struct tnode *search(struct tnode *, char *);

int main() {
  char dat[12];
  struct tnode *root, *p;

  root = NULL;
  while (scanf("%s", dat) != EOF) {
    root = gentree(root, dat);
  }

  p = root;
  while (p != NULL) {
    printf("%s\n", p->name);
    p = p->left;
  }
  return 0;
}