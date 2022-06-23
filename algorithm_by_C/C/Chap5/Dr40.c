/*
 * -----------------------------------------
 *      自己再編成探索（１つ前に移す）     *
 * -----------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tfield {
    char name[20];             // 名前
    char tel[20];              // 電話番号
    struct tfield *pointer;    // 次のデータへのポインタ
};

struct tfield *talloc(void);

void main(void)
{
    char key[20];
    struct tfield *head,*p,*old1,*old2,*q;

    head=NULL;                // リストの作成
    while (p=talloc(),scanf("%s %s",p->name,p->tel)!=EOF){
        p->pointer=head;
        head=p;
    }
    p=talloc();               // ダミー・ノード
    p->pointer=head;
    head=p;
                                                       // 探索
    while (printf("Key Name ? "),scanf("%s",key)!=EOF){
        p=head->pointer;
        old1=old2=head;
        while (p!=NULL){
            if (strcmp(key,p->name)==0){
                printf("%15s%15s\n",p->name,p->tel);
                if (p!=head->pointer){       // 先頭でないときに
                    q=old1->pointer;         // １つ前と交換
                    old1->pointer=p;
                    old2->pointer=p->pointer;
                    p->pointer=q;
                }
                break;
            }
            old1=old2;
            old2=p;
            p=p->pointer;
        }
    }
}
struct tfield *talloc(void)     // 記憶領域の取得
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
