//
//  main.c
//  h27(4)
//
//  Created by 水野桃夏 on 2020/05/20.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dict_list {
  struct dict_list *next;
  char *name;
};

#define N 100
int count = 0;
struct dict_list *bucket[N];

int h(char *str) { return *str % N; }

int h2(char *str) { return (str[0] + str[1]) % N; }

int search(char *str) {
  struct dict_list *elem;
  int i;
  i = h2(str);
  elem = bucket[i];
  while (elem) {
    if (!strcmp(elem->name, str)) return -1;
    elem = elem->next;
  }
  return i;
}

int search2(char *str) {
  struct dict_list *elem;
  int i;
  i = h2(str);
  elem = bucket[i];
  while (elem) {
    count++;
    if (!strcmp(elem->name, str)) return -1;
    elem = elem->next;
  }
  return i;
}

void insert(char *str) {
  struct dict_list *new;
  int i;

  i = search(str);
  if (i < 0) return;
  new = malloc(sizeof(struct dict_list));
  new->next = bucket[i];
  new->name = str;
  bucket[i] = new;
}

void insert2(char *str) {
  struct dict_list *new;
  int i;

  i = search2(str);
  if (i < 0) return;
  new = malloc(sizeof(struct dict_list));
  new->next = bucket[i];
  new->name = str;
  bucket[i] = new;
}

void display(void) {
  int i;
  struct dict_list *elem;
  for (i = 0; i < N; i++) {
    elem = bucket[i];
    if (elem == NULL) continue;
    printf("bucket[%d]->", i);
    while (elem) {
      printf("[%s]->", elem->name);
      elem = elem->next;
    }
    printf("[]\n");
  }
}

int main() {
  char moji[][20] = {"hydrogen", "helium", "lithium",  "beryllium",
                     "boron",    "carbon", "nitrogen", "oxygen",
                     "fluorine", "neon",   "natrium"};
  insert(moji[0]);
  insert(moji[1]);
  insert(moji[2]);
  insert(moji[3]);
  insert(moji[4]);
  insert(moji[5]);
  insert(moji[6]);
  insert(moji[7]);
  insert(moji[8]);
  insert(moji[9]);
  insert2(moji[10]);
  printf("%X\n", 'a');
  display();
  printf("%d", count);

  return 0;
}