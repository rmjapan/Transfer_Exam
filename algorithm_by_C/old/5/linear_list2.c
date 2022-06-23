/**
*    author:  shosei
*    created: 13.06.2021 17:26:03
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield
{
  char name[20];
  char tel[20];
  struct tfield *pointer;
} * head;
typedef struct tfield tf;

tf *talloc(void);
void genlist(void);
void displist(void);
void link(char *);

int main()
{
  char key[20];
  genlist();
  displist();

  while (printf("key name "), scanf("%s", key) != EOF)
  {
    link(key);
  }
  displist();
  return 0;
}

tf *talloc(void)
{
  return (struct tfield *)malloc(sizeof(struct tfield));
}

void link(char *key)
{
  tf *p, *n;
  n = talloc();
  printf("追加データ");
  scanf("%s %s", n->name, n->tel);

  p = head;
  while (p != NULL)
  {
    if (strcmp(key, p->name) == 0)
    {
      n->pointer = p->pointer;
      p->pointer = n;
      return;
    }
    p = p->pointer;
  }
  printf("key data was not faund.\n");
}

void genlist(void)
{
  tf *p;
  head = NULL;
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
  {
    p->pointer = head;
    head = p;
  }
}

void displist()
{
  tf *p;
  p = head;
  while (p != NULL)
  {
    printf("%15s %15s\n", p->name, p->tel);
    p = p->pointer;
  }
}
