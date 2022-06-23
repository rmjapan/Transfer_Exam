/*
 * -------------------
 *      ハッシュ     *
 * -------------------
 */

#include <stdio.h>
#include <string.h>

#define TableSize 1000
#define ModSize   1000

int hash(char *);

struct tel{             // データ・テーブル
    char name[20];
    char telnum[20];
} dat[TableSize];

void main(void)
{
    int n;
    char a[20],b[20];

    printf("名前 電話番号\n");
    while (scanf("%s %s",a,b)!=EOF){
        n=hash(a);
        strcpy(dat[n].name,a);
        strcpy(dat[n].telnum,b);

    }

    rewind(stdin);
    printf("検索するデータを入力してください\n");
    while (scanf("%s",a)!=EOF){
        n=hash(a);
        printf("%15s%15s\n",dat[n].name,dat[n].telnum);
    }
}
int hash(char *s)    // ハッシュ関数
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
