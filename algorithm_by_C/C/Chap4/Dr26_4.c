/*
 * ------------------------------------------
 *      ユークリッドの互除法（再帰版）      *
 * ------------------------------------------
 */

#include <stdio.h>

int gcd(int,int);

void main(void)
{
    int a,b;

    printf("２つの整数を入力してください");
    scanf("%d %d",&a,&b);

    printf("最大公約数=%d\n",gcd(a,b));
}
int gcd(int m,int n)
{
    if (m==n)
        return m;
    if (m>n)
        return gcd(m-n,n);
    else
        return gcd(m,n-m);
}
