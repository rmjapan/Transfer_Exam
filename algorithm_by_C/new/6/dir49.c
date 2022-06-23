/**
 *    author:  shosei
 *    created: 20.02.2022 22:17:00
 **/
#include <ctype.h>
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
  int ope;
  struct tnode *right;
};

struct tnode *talloc();
struct tnode *gentree(struct tnode *, char *);
void calc_tree(struct tnode *);

int main() {
  struct tnode *root;
  char expression[] = "53*64+2/-";

  root = NULL;
  root = gentree(root, expression);
  calc_tree(root);
  printf("value=%d\n", root->ope);
  return 0;
}

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

// struct tnode *gentree(struct tnode *p, char *w) {
//   int n;
//   n = strlen(w);
//   p = talloc();
//   if ('0'<=w[n-1] && w[n-1]<='9')
//     p->ope = w[n-1] - '0';
//   else
//     p->ope = w[n - 1];
//   w[n - 1] = '\0';
//   if (!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/')) {
//     p->left = p->right = NULL;
//   } else {
//     p->right = gentree(p->right, w);
//     p->left = gentree(p->left, w);
//   }

//   return p;
// }
struct tnode *gentree(struct tnode *p, char *w) {
  int n;
  n = strlen(w);
  p = talloc();
  if (isdigit(w[n - 1])) {
    p->ope = w[n - 1] - '0';
    p->left = p->right = NULL;
    w[n - 1] = '\0';
  } else {
    p->ope = w[n - 1];
    w[n - 1] = '\0';
    p->right = gentree(p->right, w);
    p->left = gentree(p->left, w);
  }
  return p;
}

void calc_tree(struct tnode *p) {
  if (p != NULL) {
    calc_tree(p->left);
    calc_tree(p->right);
    switch (p->ope) {
      case '+':
        p->ope = (p->left->ope) + (p->right->ope);
        break;
      case '-':
        p->ope = (p->left->ope) - (p->right->ope);
        break;
      case '*':
        p->ope = (p->left->ope) * (p->right->ope);
        break;
      case '/':
        p->ope = (p->left->ope) / (p->right->ope);
        break;
    }
  }
}
