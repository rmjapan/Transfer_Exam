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
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}
