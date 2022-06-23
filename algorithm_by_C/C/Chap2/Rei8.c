/*
 * --------------------------------
 *     一様乱数（線形合同法）     *
 * --------------------------------
 */

#include <stdio.h>

unsigned rndnum=13;        // 乱数の初期値

unsigned irnd(void);

void main(void)
{
    int j;
    for (j=0;j<100;j++){
        printf("%8d",irnd());
    }
    printf("\n");
}
unsigned irnd(void)        // 0～32767の整数乱数
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
