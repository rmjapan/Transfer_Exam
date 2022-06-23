/*
 * ------------------------------------
 *     モンテカルロ法によるπの計算   *
 * ------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

double rnd(void);

void main(void)
{
    double x,y,pai;
    int i,in=0;

    for (i=1;i<=NUM;i++){
        x=rnd();
        y=rnd();
        if (x*x+y*y<=1)
            in++;
    }
    pai=(double)4*in/NUM;
    printf("πの値=%f\n",pai);
}
double rnd(void)        // ０～１の乱数
{
    return (double)rand()/(RAND_MAX+0.1);
}
