/**
*    author:  shosei
*    created: 27.06.2021 23:29:30
**/
#include <stdio.h>

#define Max 100
#define nil -1

// int getch(void)
// {
//     rewind(stdin);
//     return getchar();
// }



int main()
{
    struct tnode
    {
        int left;
        char node[30];
        int right;
    };
    static struct tnode a[Max] = {{1, "闃ｸ閭ｽ莠ｺ縺ｧ縺吶°", 2},
                                  {3, "豁梧焔縺ｧ縺吶°", 4},
                                  {nil, "蜷臥伐縲闌・, nil},
                                  {nil, "莠穂ｸ翫髯ｽ豌ｴ", nil},
                                  {5, "螂ｳ蜆ｪ縺ｧ縺吶°", 6},
                                  {nil, "荳ｭ螻ｱ縲鄒守ｩ・, nil},
                                  {nil, "荵・ｱｳ 螳・, nil}};

    int p, lp = 6, c;
    do
    {
        p = 0;
        while (a[p].left != nil)
        {
            printf("\n%s y/n ", a[p].node);
            c = getchar();
            if (c == 'y' || c == 'Y')
                p = a[p].left;
            else
                p = a[p].right;
        }
        printf("\n 遲斐∴縺ｯ %s 縺ｧ縺・\n 豁｣縺励＞縺ｧ縺吶°・・y/n", a[p].node);
        c = getchar();
        if (c == 'n' || c == 'N')
        {
            a[lp + 1] = a[p]; //繝弱・繝峨・遘ｻ蜍・
            printf("縺ゅ↑縺溘・閠・∴縺ｯ・滂ｼ・");
            scanf("%s", a[lp + 2].node);
            a[lp + 2].left = a[lp + 2].right = nil;

            printf("%s縺ｨ%s繧貞玄蛻･縺吶ｋ雉ｪ蝠上・・・", a[lp + 1].node, a[lp + 2].node);
            scanf("%s", a[p].node);
            printf("Yes縺ｮ鬆・岼縺ｯ%s縺ｧ縺・＞縺ｧ縺吶°y/n", a[lp + 1].node);
            c = getchar();
            if (c == 'y' || c == 'Y')
            {
                a[p].left = lp + 1;
                a[p].right = lp + 2;
            }
            else
            {
                a[p].left = lp + 2;
                a[p].right = lp + 1;
            }
            lp = lp + 2;
        }

    } while (printf("\n 邯壹￠縺ｾ縺吶°・・y/n "), c = getchar(), c == 'y' || c == 'Y');
    printf("\n");
    return 0;
}
