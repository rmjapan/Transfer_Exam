/**
*    author:  shosei
*    created: 14.06.2021 23:00:57
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield
{
  char name[20];
  char tel[20];
  struct tfield *left;
  struct tfield *right;
};

struct tfield *talloc();

int main()
{
  struct tfield *head, *tail, *p;

  tail = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
  {
    p->left = tail;
    tail = p;
  }

  p = tail;
  head = NULL;
  while (p != NULL)
  {
    p->right = head;
    head = p;
    p = p->left;
  }

  printf("純方向リスト\n");
  p = head;
  while (p != NULL)
  {
    printf("%s %s", p->name, p->tel);
    p = p->right;
  }
  printf("逆方向リスト\n");
  p = tail;
  while (p != NULL)
  {
    printf("%s %s", p->name, p->tel);
    p = p->left;
  }
  return 0;
}

struct tfield *talloc()
{
  return (struct tfield *)malloc(sizeof(struct tfield));
}
