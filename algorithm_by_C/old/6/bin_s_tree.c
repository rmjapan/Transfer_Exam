/**
*    author:  shosei
*    created: 21.06.2021 22:25:18
**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tnode
{
  struct tnode *left;
  char name[20];
  struct tnode *right;
};
struct tnode *talloc()
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

int main()
{
  char dat[12];
  struct tnode *old, *p, *root;

  root = talloc(); //ルートノード
  scanf("%s", root->name);
  root->left = root->right = NULL;

  //ニ分木生成
  //順番が違うと同じ木にはならないが，左が小さく右が大きいという性質は保たれる

  while (scanf("%s", dat) != EOF)
  {
    p = root;
    while (p != NULL)
    {
      old = p;
      if (strcmp(dat, p->name) <= 0)
        p = p->left;
      else
        p = p->right;
    }
    p = talloc();
    strcpy(p->name, dat);
    p->left = p->right = NULL;
    if (strcmp(dat, old->name) <= 0)
      old->left = p;
    else
      old->right = p;
  }

  p = root;
  while (p->left != NULL)
    p = p->left;
  printf("min_node = %s\n", p->name);

  p = root;
  while (p->right != NULL)
    p = p->right;
  printf("max_node = %s\n", p->name);

  return 0;
}
