//
//  main.c
//  h23(3)
//
//  Created by 水野桃夏 on 2020/04/23.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define Nil 0
#define Cell 0
#define IntCell 1

typedef struct cell *pntr;

struct cell {
  char tag;
  int data;
  pntr left;
  pntr right;
};

pntr fi(int i) {
  pntr c = (pntr *)malloc(sizeof(struct cell));
  c->tag = IntCell;
  c->data = i;
  c->left = Nil;
  c->right = Nil;
  return c;
}

pntr f0(pntr l, pntr r) {
  pntr c = (pntr *)malloc(sizeof(struct cell));
  c->tag = Cell;
  c->data = 0;
  c->left = l;
  c->right = r;
  return c;
}

pntr f1(pntr p) { return p->left; }

pntr f2(pntr p) { return p->right; }

int g0(pntr p) {
  if (p == Nil)
    return 0;
  else
    return 1 + g0(f2(p));
}

pntr g1(int low, int high) {
  if (low == high)
    return f0(fi(high), Nil);
  else
    return f0(fi(low), g1(low + 1, high));
}

pntr g2(pntr p1, pntr p2) {
  if (p1 == Nil)
    return p2;
  else
    return f0(f1(p1), g2(f2(p1), p2));
}

void printAux(pntr p) {
  if (p == Nil)
    return;
  else {
    if (f1(p)->tag == Cell) {
      printf("(");
      printAux(f2(p));
      printf(") ");
    } else if (f1(p)->tag == IntCell) {
      printf("%d", f1(p)->data);
      if (f2(p) != Nil) printf(" ");
    }
    printAux(f2(p));
  }
}

void printList(pntr p) {
  printf("(");
  printAux(p);
  printf(")\n");
}

int main(int argc, const char *argv[]) {
  pntr i0 = fi(0);
  pntr i1 = fi(1);
  pntr i2 = fi(2);
  pntr list0 = f0(i0, f0(i1, f0(i2, Nil)));
  //    pntr list1=f0(i0,list0);
  //    pntr list2=f0(list0,list0);
  printf("list0=");
  printList(list0);
  //    printf("list1="); printList(list1);
  //    printf("list2="); printList(list2);
  //    printf("g0(list2)=%d\n",g0(list2));
  //    printf("g1(1,5)="); printList(g1(1, 5));
  //    printf("g2(list0,list1)="); printList(g2(list0, list1));
  return 0;
}
