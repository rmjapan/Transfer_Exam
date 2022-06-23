/**
 *    author:  shosei
 *    created: 22.02.2022 22:36:42
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
  char node[30];
  struct tnode *right;
};

struct tnode *talloc() {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

int getch() {
  rewind(stdin);
  return getchar();
}

int main() {
  struct tnode *root, *p, *q1, *q2;
  int c;

  root = talloc();
  printf("初期ノード ? ");
  scanf("%s", root->node);
  root->left = root->right = NULL;

  do {
    p = root;
    while (p->left != NULL) {
      printf("\n %s y/n ", p->node);
      c = getch();
      if (c == 'y' || c == 'Y')
        p = p->left;
      else
        p = p->right;
    }

    printf("\n 答えは %s です\n正しいですか？ y/n", p->node);
    c = getch();

    if (c == 'n' || c == 'N') {
      q1 = talloc();
      *q1 = *p;  //学習

      q2 = talloc();
      printf("\nあなたの考えは？ ");
      scanf("%s", q2->node);
      q2->left = q2->right = NULL;

      printf("%s と %s を区別する質問は？ ", q1->node, q2->node);
      scanf("%s", p->node);
      printf("yesの項目は %s でイイですか？ y/n", q1->node);
      c = getch();
      if (c == 'y' || c == 'Y') {
        p->left = q1;
        p->right = q2;
      } else {
        p->left = q2;
        p->right = q1;
      }
    }
  } while (printf("\n 続けますか？ y/n "), c = getch(), c == 'Y' || c == 'y');
  printf("\n");
  return 0;
}