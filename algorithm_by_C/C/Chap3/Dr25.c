/*
 * -------------------
 *      ハッシュ     *
 * -------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1050
#define ModSize      1000

int hash(char *);

struct tel{             // データ・テーブル
    char name[20];
    char telnum[20];
    int empty;
} dat[TableSize];

void main(void)
{
    int n;
    char a[20],b[20];

    printf("名前 電話番号\n");
    while (scanf("%s %s",a,b)!=EOF){
        n=hash(a);
        while (dat[n].empty==1 && n<TableSize)
            n++;
        if (n<TableSize){
            strcpy(dat[n].name,a);
            strcpy(dat[n].telnum,b);
            dat[n].empty=1;
        }
        else
            printf("表が一杯です\n");
    }

    rewind(stdin);
    printf("検索するデータを入力してください\n");
    while (scanf("%s",a)!=EOF){
        n=hash(a);
        while (strcmp(a,dat[n].name)!=0 && n<TableSize)
            n++;
        if (n<TableSize)
            printf("%15s%15s\n",dat[n].name,dat[n].telnum);
        else
            printf("デ－タは見つかりませんでした\n");
    }
}
int hash(char *s)        // ハッシュ関数
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
