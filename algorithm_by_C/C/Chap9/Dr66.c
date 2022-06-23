/*
 * -------------------------
 *      騎士巡歴の問題     *
 * -------------------------
 */

#include <stdio.h>

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    // 盤面
    dx[8]={2,1,-1,-2,-2,-1,1,2},    // 騎士の移動ｘ成分
    dy[8]={1,2,2,1,-1,-2,-2,-1};    // 騎士の移動ｙ成分

void main(void)
{
    int i,j;

    for (i=0;i<=N+3;i++){
        for (j=0;j<=N+3;j++){
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      // 盤面
            else
                m[i][j]=1;      // 壁
        }
    }
    backtrack(2,2);
}
void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;  // static指定必要

    if (m[x][y]==0){
        m[x][y]=++count;         // 訪問順番の記録
        if (count==N*N){
            printf("\n解%d\n",++num);    // 解の表示
            for (i=2;i<=N+1;i++){
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
        }
        else
            for (k=0;k<8;k++)           // 進む位置を選ぶ
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      // １つ前に戻る
        count--;
    }
}
