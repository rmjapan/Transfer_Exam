﻿/*
 * -----------------------------------------------
 *      リストデータの作成（ダミー・ノード）     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct tfield {
    char name[20];             // 名前
    char tel[20];              // 電話番号
    struct tfield *pointer;    // 次のデータへのポインタ
};

struct tfield *talloc(void);

void main(void)
{
    struct tfield *head,*p,*old;

    head=talloc();      // ダミー・ノードの作成
    old=head;
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        old->pointer=p;
        old=p;
    }
    old->pointer=NULL;

    p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
}
struct tfield *talloc(void)     // 記憶領域の取得
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
