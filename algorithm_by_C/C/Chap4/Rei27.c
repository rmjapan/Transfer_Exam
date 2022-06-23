﻿/*
 * ---------------------------
 *     階乗計算の非再帰解    *
 * ---------------------------
 */

#include <stdio.h>

long kaijo(int);

void main(void)
{
    int n;
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));
}
long kaijo(int n)   // 階乗
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}
