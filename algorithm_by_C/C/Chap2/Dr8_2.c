/*
 * -------------------------------------------
 *      正規乱数（ボックス・ミュラー法）     *
 * -------------------------------------------
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.141593

void brnd(double, double, double *, double *);

void main(void)
{
    int i, j, hist[100];
    double x, y;

    for (i = 0; i < 100; i++)
        hist[i] = 0;

    for (i = 0; i < 1000; i++)
    {
        brnd(1.0, 10, &x, &y);
        hist[(int)x]++;
        hist[(int)y]++;
    }

    for (i = 0; i <= 20; i++)
    { // ヒスト・グラムの表示
        printf("%3d : I ", i);
        for (j = 1; j <= hist[i] / 10; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void brnd(double sig, double m, double *x, double *y)
{
    double r1, r2;
    r1 = rand() / (RAND_MAX + 0.1);
    r2 = rand() / (RAND_MAX + 0.1);
    *x = sig * sqrt(-2 * log(r1)) * cos(2 * pi * r2) + m;
    *y = sig * sqrt(-2 * log(r1)) * sin(2 * pi * r2) + m;
}
