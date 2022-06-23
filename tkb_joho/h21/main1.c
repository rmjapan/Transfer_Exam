//
//  main.c
//  h21(3)
//
//  Created by 水野桃夏 on 2020/04/20.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 10

void pascal1(){
    int pas[N][N],i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            pas[i][j]=-1;
    pas[0][0]=1;
    pas[1][0]=pas[1][1]=1;

    for(i=2;i<N;i++){
        pas[i][0]=1;
        for(j=1;j<i;j++){
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
        pas[i][i]=1;
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%3d ",pas[i][j]);
        }
        printf("\n");
    }
}

void pascal2(){
    int *pas[N],i,j;
    for(i=0;i<N;i++)
        pas[i]=(int *)malloc(sizeof(int)*(i+1));

    pas[0][0]=1;
    pas[1][0]=pas[1][1]=1;
    for(i=2;i<N;i++){
        pas[i][0]=pas[i][i]=1;
        for(j=1; j<i; j++){
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j];
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<i+1;j++)
            printf("%3d ",pas[i][j]);
        printf("\n");
    }
}

struct join{
    int value;
    struct join *next;
};

struct join *newentry(int value,struct join *next){
    struct join *e=(struct join*)malloc(sizeof(struct join));
    e->value=value;
    e->next=next;
    return e;
}
void pascal3(){
    struct join *pas[N],*p,*q;
    int i,j;
    pas[0]=newentry(1, NULL);
    pas[1]=newentry(1, newentry(1, NULL));

    for(i=2;i<N;i++){
        p=pas[i-1];
        q=pas[i]=newentry(1, NULL);
        for(j=1;j<i;j++){
            q->next=newentry(p->value+p->next->value, NULL);
            p=p->next;
            q=q->next;
        }
        q->next=newentry(1, NULL);
    }
    for(i=0;i<N;i++){
        for(p=pas[i];p->next!=NULL;p=p->next){
            printf("%3d ",p->value);
        }
        printf("%3d \n",p->value);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    pascal3();
    return 0;
}
