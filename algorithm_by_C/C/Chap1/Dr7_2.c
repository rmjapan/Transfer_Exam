/*
 * ---------------------------------------
 *        エラトステネスのふるい         *
 * ---------------------------------------
 */

#include <stdio.h>
#include <math.h>

#define NUM 1000

void main(void)
{
    int prime[NUM + 1];
    int i, j, Limit;
    int cnt = 0;

    for (i = 2; i <= NUM; i++)
        prime[i] = 1;

    Limit = (int)sqrt((double)NUM);
    for (i = 2; i < Limit; i++)
    {
        if (prime[i] == 1)
        {
            for (j = i * 2; j <= NUM; j++)
            {
                if (j % i == 0)
                    prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= NUM; i++)
    {
        if (prime[i] == 1)
        {
            printf("%3d ", i);
            cnt++;
        }
        else
        {
            continue;
        }
        if (cnt % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
