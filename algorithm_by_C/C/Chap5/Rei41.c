﻿/*
 * -----------------------------------------------
 *      リストを用いたハッシュ（先頭に追加）     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tfield{
    char name[20];
    char tel[20];
    struct tfield *pointer;
} *dat[TableSize];               // ポインタ・テーブル

struct tfield *talloc(void);

void main(void)
{
    int n;
    char key[20];
    struct tfield *p;

    for (n=0;n<TableSize;n++)    // ポインタ・テーブルの初期化
        dat[n]=NULL;

    printf("名前 電話番号\n");
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        n=hash(p->name);         // ハッシング
        p->pointer=dat[n];       // 先頭に追加
        dat[n]=p;
    }

    rewind(stdin);                                  // 探索
    printf("\n探索するデータを入力してください\n");
    while (scanf("%s",key)!=EOF){
        n=hash(key);
        p=dat[n];
        while (p!=NULL){
            if (strcmp(key,p->name)==0)
                printf("%15s%15s\n",p->name,p->tel);
            p=p->pointer;
        }
    }
}
int hash(char *s)    // ハッシュ関数
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        // 記憶領域の取得
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
