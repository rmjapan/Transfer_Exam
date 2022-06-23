/*
 * -------------------------
 *     階乗計算の再帰解    *
 * -------------------------
 */

#include <stdio.h>

long kaijo(int);

void main(void)
{
    int n;
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));
}
long kaijo(int n)   // 再帰手続
{
    if (n==0)
        return 1L;
    else
        return n*kaijo(n-1);
}
