/*
 * ------------------------------
 *      ハノイの塔の再帰解      *
 * ------------------------------
 */

#include <stdio.h>

void hanoi(int,char,char,char);

void main(void)
{
    int n;
    printf("円盤の枚数 ? ");
    scanf("%d",&n);

    hanoi(n,'a','b','c');
}
void hanoi(int n,char a,char b,char c)  // 再帰手続
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d番の円盤を %c から %c に移動\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}
