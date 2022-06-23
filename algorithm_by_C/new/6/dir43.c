/**
*    author:  shosei
*    created: 18.02.2022 21:57:07
**/
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

struct tnode {
  struct tnode *left;
  char name[12];
  struct tnode *right;
};

struct tnode *talloc(){
  return (struct tnode *)malloc(sizeof(struct tnode));
}

int main()
{
  char dat[30];
  struct tnode *root,*p, *old;

  root = talloc(); //rootノードの作成
  scanf("%s",root->name);
  root->left = root->right = NULL;

  while(scanf("%s",dat) !=EOF){
    p=root;
    while(p!=NULL){ //木のサーチ
      old=p;
      if(strcmp(dat, p->name)<=0)
        p = p->left;
      else
        p = p->right;
    }
    //新しいノードの作成
    p = talloc();
    p->right = p->left = NULL;
    strcpy(p->name, dat);
    if(strcmp(dat, old->name)<=0)
      old->left = p;
    else
      old->right = p;
  }
  return 0;
}