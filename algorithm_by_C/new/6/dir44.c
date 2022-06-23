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
  char key[12];
  struct tnode *root, *p;

  root = NULL;
  while (scanf("%s", key) != EOF) {
    root = gentree(root, key);
  }

  rewind(stdin);
  while(printf("Search name -->"), scanf("%s",key) !=EOF){
    if((p = search(root, key)) == NULL)
      printf("%s was faund\n",p->name);
    else
      printf("Not faund\n");
  }
  return 0;
}

struct tnode *search(struct tnode *p, char *key){
  if(p==NULL || strcmp(key, p->name) == 0){
    return p;
  }else if(strcmp(key, p->name)<0)
    return search(p->left, key);
  else
    return search(p->right, key);
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
