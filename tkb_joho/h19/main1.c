//
//  main.c
//  h19(3)
//
//  Created by 水野桃夏 on 2020/08/02.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 100
typedef struct node Node;

struct node {
  char label;
  int value;
  Node *child;
  Node *sister;
};

Node *make_node(char label, int value, Node *parent) {
  Node *newnode;
  newnode = malloc(sizeof(Node));
  newnode->label = label;
  newnode->value = value;
  newnode->child = NULL;
  if (parent != NULL) {
    newnode->sister = parent->child;
    parent->child = newnode;
  }
  //    printf("%d\n",newnode->value);
  return newnode;
}

void print_tree(Node *s, int indent) {
  int i;
  if (s == NULL) return;
  for (i = 0; i < indent; i++) printf("*");
  printf("%c:%d\n", s->label, s->value);
  print_tree(s->child, ++indent);
  print_tree(s->sister, --indent);
  //    if(s->child!=NULL){
  //        print_tree(s->child,++indent);
  //        indent--;
  //    }
  //    print_tree(s->sister, indent);
}

Node *list[QUEUESIZE];
int p0 = 0;
int p1 = 0;

int is_empty() { return (p0 == p1); }

void enqueue(Node *node) {
  if (p1 == QUEUESIZE) p0 = 0;
  list[p1++] = node;
}
Node *dequeue() {
  if (p0 == QUEUESIZE) p0 = 0;
  return list[p0++];
}

int question1(Node *node, char key) {
  int value = -1;
  if (node == NULL) return value;
  if (node->label == key) {
    return node->value;
  } else {
    value = question1(node->child, key);
    if (value == -1) value = question1(node->sister, key);
    return value;
  }
}

int question2(Node *node, char key) {
  int value = -1;
  p0 = p1 = 0;
  enqueue(node);
  do {
    node = dequeue();
    if (node->label == key) {
      value = node->value;
    } else {
      Node *child = node->child;
      while (child != NULL) {
        enqueue(child);
        child = child->sister;
      }
    }
  } while (value == -1 && !is_empty());
  return value;
}
int main() {
  Node *s1, *s2, *s3, *s4;
  s1 = make_node('A', 10, NULL);
  s2 = make_node('B', 20, s1);
  s3 = make_node('E', 30, s1);
  s4 = make_node('C', 40, s1);
  make_node('B', 50, s4);
  make_node('D', 60, s2);
  print_tree(s1, 0);
  //    int value1=question1(s1, 'B');
  //    int value2=question2(s1, 'B');
  //    printf("%d,%d",value1,value2);
  return 0;
}