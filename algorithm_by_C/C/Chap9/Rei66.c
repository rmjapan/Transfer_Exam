﻿/*
 * -----------------------------------------
 *      八王妃（８Ｑｕｅｅｎｓ）の問題     *
 * -----------------------------------------
 */

#include <stdio.h>

void backtrack(int);

#define N 8
int column[N+1],    // 同じ欄に王妃が置かれているかを表す
    rup[2*N+1],     // 右上がりの対角線上に置かれているかを表す
    lup[2*N+1],     // 左上がりの対角線上に置かれているかを表す
    queen[N+1];     // 王妃の位置

void main(void)
{
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;

    backtrack(1);
}
void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N){
        printf("\n解 %d \n",++num);        // 解の表示
        for (y=1;y<=N;y++){
            for (x=1;x<=N;x++){
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            }
            printf("\n");
        }
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                // （ｉ，ｊ）が王妃の位置
                column[j]=rup[i+j]=lup[i-j+N]=0;    // 局面の変更
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    // 局面の戻し
            }
        }
    }
}
