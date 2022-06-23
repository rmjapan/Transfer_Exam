/**
*    created by: shosei
*    2022.06.20. 11:17:30
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a)<(b)) ? (a) : (b)
#define max(a, b) ((a)>(b)) ? (a) : (b)

struct tnode {
  struct tnode *left;
  char name[12];
  struct tnode *right;
};

struct tnode *talloc(void);

void tree_walk(struct tnode *p, int depth){
  for(int i = 0; i<depth; i++) printf("*");
  printf("%s\n", p->name);

  if(p->left != NULL) tree_walk(p->left, depth+1);
  if(p->right != NULL) tree_walk(p->right, depth+1);
}

int main()
{
  char dat[12];
  struct tnode *root, *p, *old;

  root = talloc();
  scanf("%s", root->name);
  root->left = root->right = NULL;

  while(scanf("%s", dat) != EOF){
    p = root;
    while(p != NULL){
      old = p;
      if(strcmp(dat, p->name) <= 0){
        p = p->left;
      }else
        p = p->right;
    }

    //データを挿入
    p = talloc();
    strcpy(p->name, dat);
    p->left = p->right = NULL;
    if(strcmp(dat, old->name) <= 0)
      old->left = p;
    else
      old->right = p;
  }
  tree_walk(root, 0);
  return 0;
}

struct tnode *talloc(){
  return (struct tnode *)malloc(sizeof(struct tnode));
}