﻿/*
 * -------------------------------------------------
 *      逆ポーランド記法（かっこの処理を含む）     *
 * -------------------------------------------------
 */

#include <stdio.h>

char stack[50],polish[50];
int pri[256];                   // 優先順位テーブル
int sp1,sp2;                    // スタック・ポインタ

void main(void)
{
    int i;
    char *p="(a+b)*(c+d)";      // 式

    for (i=0;i<=255;i++)        // オペランドの優先順位
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;    // 演算子の優先順位
    pri['(']=4; pri[')']=0;

    stack[0]=0;pri[0]=-1;       // 番兵
    sp1=sp2=0;
    while  (*p!='\0'){
        while (pri[*p]<=pri[stack[sp1]] && stack[sp1]!='(')
            polish[++sp2]=stack[sp1--];
        if (*p!=')')
            stack[++sp1]=*p;
        else
            sp1--;
        p++;

    }
    for (i=sp1;i>0;i--)        // スタックの残りを取り出す
        polish[++sp2]=stack[i];

    for (i=1;i<=sp2;i++)       // 逆ポーランド式の表示
        putchar(polish[i]);
    printf("\n");
}
