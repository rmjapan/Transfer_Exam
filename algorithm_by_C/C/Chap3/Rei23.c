﻿/*
 * -------------------------------------
 *      文字列の照合（単純な方法）     *
 * -------------------------------------
 */

#include <stdio.h>
#include <string.h>

char *search(char *,char *);

void main(void)
{
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";

    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
