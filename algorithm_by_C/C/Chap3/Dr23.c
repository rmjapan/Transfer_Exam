﻿/*
 * ---------------------------------------------------
 *      文字列の照合（Ｂｏｙｅｒ－Ｍｏｏｒｅ法）     *
 * ---------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

char *search(char *,char *);
void table(char *);

int skip[256];

void main(void)
{
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";

    table(key);
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
}
void table(char *key)      // スキップ・テーブルの作成
{
    int k,n;

    n=strlen(key);
    for (k=0;k<=255;k++)
        skip[k]=n;
    for (k=0;k<n-1;k++)
        skip[key[k]]=n-1-k;
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);

    p=text+n-1;
    while (p<text+m){
        if (*p==key[n-1]){                   // 右端の文字だけ比較
            if (strncmp(p-n+1,key,n)==0)     // キー全体を比較
                return p-n+1;
        }
        p=p+skip[*p];                        // サーチ位置を進める
    }
    return NULL;
}
