﻿/*
 * -------------------------------------------
 *      迷路をたどる（１つだけ見つける）     *
 * -------------------------------------------
 */

#include <stdio.h>

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;

int visit(int,int);

void main(void)
{
    success=0;                  // 脱出に成功したかを示すフラグ
    Si=1; Sj=1; Ei=5; Ej=5;     // 入口と出口の位置

    printf("\n迷路の探索\n");
    if (visit(Si,Sj)==0)
        printf("出口は見つかりませんでした\n");
    printf("\n");
}
int visit(int i,int j)
{
    m[i][j]=1;                // 訪れた位置に印をつける

    if (i==Ei && j==Ej)       // 出口に到達したとき
        success=1;
                               // 出口に到達しない間迷路をさまよう
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          // 通過点の表示
        printf("(%d,%d) ",i,j);
    return success;
}
