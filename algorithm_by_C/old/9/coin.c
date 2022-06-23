#include <stdio.h>

#define limit 42
#define n 3 //コインの種類

int main()
{
    int coin[] = {1, 10, 25};
    int num[limit + 1],
        item[limit + 1],
        newvalue,
        i, s, p;
    for (s = 0; s <= limit; s++)
        num[s] = s;
    for (i = 0; i <= n; i++)
    {
        for (s = coin[i]; s <= limit; s++)
        {
            p = s - coin[i];
            newvalue = num[p] + 1;
            if (newvalue <= num[s])
            {
                num[s] = newvalue;
                item[s] = i;
            }
        }
    }
    printf("コインの枚数　= %3d : ", num[limit]);
    for (s = limit; s > 0; s = s - coin[item[s]])
    {
        printf("%2d,", coin[item[s]]);
    }
    printf("\n");
    return 0;
}
