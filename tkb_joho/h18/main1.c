//
//  main.c
//  h18(3)
//
//  Created by 水野桃夏 on 2020/04/18.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;

struct node {
    int item;
    link next;
};

void makelist(link top,int n);
void printlist(char *mag,link top);
void rev(link top);
void rev2(link top1,link top2);

int main(int argc, const char * argv[]) {
    link top0=malloc(sizeof(struct node));
    link top1,top2;

    top0->item=-1;
    top0->next=NULL;
    makelist(top0, 4);
    printlist("(2) ", top0);
    rev(top0);
    printlist("(4) ", top0);

    top1=malloc(sizeof(struct node));
    top2=malloc(sizeof(struct node));

    top1->item=top2->item=-1;
    makelist(top1, 4);
    rev2(top1,top2);
    printlist("(4) ", top2);
    return 0;
}

void makelist(link top,int n){
    int i;
    link x,p=top;

    for(i=0;i<n;i++){
        x=malloc(sizeof(struct node));
        x->item=i;
        x->next=NULL;
        p->next=x;
        p=x;
    }
}

void printlist(char *mag,link top){
    link x=top->next;
    printf("%s",mag);
    while(x!=NULL){
        printf("%d ",x->item);
        x=x->next;
    }
    printf("\n");
}

void rev(link top){
    link p=NULL,q,x=top->next;

    while(x!=NULL){
        q=x->next;
        x->next=p;
        p=x;
        x=q;
    }
    top->next=p;
}

void rev2(link top1,link top2){
    link p=NULL,x=top1->next,y;

    while(x!=NULL){
        y=malloc(sizeof(struct node));
        y->item=x->item;
        y->next=p;
        x=x->next;
        p=y;
    }
    top2->next=p;
}