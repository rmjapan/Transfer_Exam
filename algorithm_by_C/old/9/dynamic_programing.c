/**
*    author:  shosei
*    created: 06.07.2021 00:31:28
**/
#include <stdio.h>
#define n 5
#define limit 8
#define min 1
int main()
{
    struct body
    {
        char name[20];
        int size;
        long price;
    } a[] = {{"plum", 4, 4500}, {"apple", 5, 5700}, {"orange", 2, 2250}, {"strawberry", 1, 1100}, {"melon", 6, 6700}};
    long value[limit + 1], newvalue;
    int i, s, p, item[n];
    for (i = 0; i <= limit; i++)
        value[i] = 0;

    for (i = 0; i < n; i++)
    {
        for (s = a[i].size; s <= limit; s++)
        {
            p = s - a[i].size;
            newvalue = value[p] + a[i].price;
            if (newvalue > value[s])
            {
                value[s] = newvalue;
                item[s] = i;
            }
        }
    }
    printf("     蜩√逶ｮ縲縲萓｡縲譬ｼ\n");
    for (s = limit; s >= min; s = s - a[item[s]].size)
    {
        printf("%10s%10ld\n", a[item[s]].name, a[item[s]].price);
    }
    printf("     蜷・險・10ld\n", value[limit]);
    return 0;
}
