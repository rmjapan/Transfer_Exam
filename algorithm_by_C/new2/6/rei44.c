/**
 *    created by: shosei
 *    2022.06.20. 11:35:38
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

void tree_walk(struct tnode *p, int depth) {
  for (int i = 0; i < depth; i++) printf("*");
  printf("%s\n", p->name);

  if (p->left != NULL) tree_walk(p->left, depth + 1);
  if (p->right != NULL) tree_walk(p->right, depth + 1);
}

struct tnode *gentree(struct tnode *p, char *w) {
  //ベースケース
  if (p == NULL) {
    p = talloc();
    strcpy(p->name, w);
    p->left = p->right = NULL;
    return p;
  }

  if (strcmp(w, p->name) <= 0)
    p->left = gentree(p->left, w);
  else
    p->right = gentree(p->right, w);
  return p;
}

struct tnode *search(struct tnode *p, char *key) {
  if (p == NULL || strcmp(key, p->name) == 0) return p;

  if (strcmp(key, p->name) < 0)
    return search(p->left, key);
  else
    return search(p->right, key);
}

int main() {
  char dat[12], key[12];
  struct tnode *root, *p;

  root = NULL;
  while (scanf("%s", dat) != EOF) {
    root = gentree(root, dat);
  }
  tree_walk(root, 0);

  rewind(stdin);
  while(printf("Seach name :"), scanf("%s", key) != EOF){
    if((p = search(root, key)) != NULL)
      printf("%s が見つかりました\n", key);
    else
      printf("%s is not faund\n", key);
  }

  return 0;
}