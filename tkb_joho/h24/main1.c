//
//  main.c
//  H24(3)
//
//  Created by 水野桃夏 on 2020/03/21.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
  char name[10];
  int point;
  struct record *next;
};
struct record *head = NULL;

void insert_record(char *name, int x) {
  struct record *p, *q, *t;
  t = (struct record *)malloc(sizeof(struct record));
  strcpy(t->name, name);
  t->point = x;

  q = NULL;
  for (p = head; p != NULL; p = p->next) {
    if (p->point >= x) break;
    q = p;
  }
  if (q != NULL)
    q->next = t;
  else
    head = t;
  t->next = p;
}

int main(int argc, char *argv[]) {
  // insert code here...
  FILE *fp;
  struct record *p;
  int x;
  char name[10], buf[256];

  if (argc != 2) {
    printf("missing file argument\n");
    return 1;
  }
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("can't open%s\n", argv[1]);
    return 1;
  }
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    sscanf(buf, "%s %d", name, &x);
    insert_record(name, x);
  }
  fclose(fp);

  p = head;
  while (p != NULL) {
    printf("%s %d\n", p->name, p->point);
    p = p->next;
  }
  return 0;
}