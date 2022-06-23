﻿/*
 * ------------------------------
 *      nＣrの計算（再帰版）    *
 * ------------------------------
 */

#include <stdio.h>

long combi(int,int);

void main(void)
{
    int n,r;

    for (n=0;n<=5;n++) {
        for (r=0;r<=n;r++)
            printf("%dＣ%d=%ld  ",n,r,combi(n,r));
        printf("\n");
    }
}
long combi(int n,int r)
{
    if (r==0 || r==n)
        return 1L;
    else
        return combi(n-1,r)+combi(n-1,r-1);
}
