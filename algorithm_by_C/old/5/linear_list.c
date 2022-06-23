/**
*    author:  shosei
*    created: 13.06.2021 16:57:24
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tfield
{
  char name[20];
  char tel[20];
  struct tfield *pointer;
};

struct tfield *talloc()
{
  return (struct tfield *)malloc(sizeof(struct tfield));
}

int main()
{
  char name[20];
  char tel[20];
  struct tfield *head = NULL, *p;
  printf("蜷榊燕縺ｨ髮ｻ隧ｱ逡ｪ蜿ｷ繧貞・蜉帙＠縺ｪ縺輔＞\n");
  while (p = talloc(), scanf("%s %s", p->name, p->tel) != EOF)
  {
    p->pointer = head;
    head = p;
  }
  for (head; head != NULL; head = head->pointer)
    printf("%s %s\n", head->name, head->tel);
  return 0;
}
