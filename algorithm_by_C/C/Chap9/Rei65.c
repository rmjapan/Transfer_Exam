﻿/*
 * -------------------------------
 *      戦略を持つじゃんけん     *
 * -------------------------------
 */

#include <stdio.h>

void main(void)
{
    int man,computer,M,judge;
    int table[3][3]={{0,0,0},    // 戦略テーブル
                     {0,0,0},
                     {0,0,0}},
        hist[3]={0,0,0};    // 勝敗の度数
    char *hand[3]={"グー","チョキ","パー"};

    M=0;
    while (1) {
        if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
            computer=2;
        else if (table[M][1]>table[M][2])
            computer=0;
        else
            computer=1;

        printf("0:グー　1:チョキ  2:パー\n");
        printf("あなたの手 ");scanf("%d",&man);

        printf("コンピュータの手 %s\n",hand[computer]);

        judge=(computer-man+3)%3;
        switch (judge){
            case 0: printf("ひきわけ\n");break;
            case 1: printf("あなたの勝ち\n");break;
            case 2: printf("コンピュータの勝ち\n");break;
        }
        hist[judge]++;
        table[M][man]++;        // 学習
        M=man;
        printf("--- %d勝%d敗%d分 ---\n\n",hist[1],hist[2],hist[0]);
    }
}
