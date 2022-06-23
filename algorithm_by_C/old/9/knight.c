#include <stdio.h>

void backtrack(int, int);
#define N 5

int m[N + 4][N + 4],
    dx[8] = {2, 1, -1, -2, -2, -1, 1, 2},
    dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    int i, j;

    for (i = 0; i <= N + 3; i++)
    {
        for (j = 0; j <= N + 3; j++)
        {
            if (2 <= i && i <= N + 1 && 2 <= j && j <= N + 1)
                m[i][j] = 0;
            else
                m[i][j] = 1;
        }
    }
    backtrack(2, 2);
    return 0;
}

void backtrack(int x, int y)
{
    static int num = 0, count = 0;
    int i, j, k;
    if (m[x][y] == 0)
    {
        m[x][y] = ++count;
        if (count == N * N)
        {
            printf("隗｣ %d \n", ++num);
            for (i = 2; i <= N + 1; i++)
            {
                for (j = 2; j <= N + 1; j++)
                {
                    printf("%d ", m[i][j]);
                }
                printf("\n");
            }
        }
        else
        {
            for (k = 0; k < 8; k++)
                backtrack(x + dx[k], y + dy[k]);
        }
        m[x][y] = 0;
        count--; //謌ｻ縺｣縺ｦ縺上ｋ縺ｨ縺阪↓N*N縺ｫ縺ｪ縺｣縺溘き繧ｦ繝ｳ繝医ｒ謌ｻ縺・
    }
}
