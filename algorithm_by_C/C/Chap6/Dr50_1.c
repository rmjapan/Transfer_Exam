/*
 * ---------------------------------------
 *      質疑応答と決定木（動的表現）     *
 * ---------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    struct tnode *left;        // 左の子へのポインタ
    char node[30];
    struct tnode *right;       // 右の子へのポインタ
};
struct tnode *talloc(void);

int getch(void)
{
    rewind(stdin);
    return getchar();
}

void main(void)
{
    struct tnode *root,*p,*q1,*q2;
    int c;

    root=talloc();
    printf("初期ノード ? ");scanf("%s",root->node);
    root->left=root->right=NULL;
    do {
        p=root;                             // 木のサーチ
        while (p->left!=NULL){
            printf("\n%s y/n ",p->node);c=getch();
            if (c=='Y' || c=='y')
                p=p->left;
            else
                p=p->right;
        }

        printf("\n答えは %s です。\n正しいですか y/n ",p->node);
        c=getch();

        if (c=='n' || c=='N'){                         // 学習
            q1=talloc(); *q1=*p;        // ノードの移動

            q2=talloc();                // 新しいノードの作成
            printf("\nあなたの考えは ? ");scanf("%s",q2->node);
            q2->left=q2->right=NULL;
                                        // 質問ノードの作成
            printf("%s と %s を区別する質問は ? ",q1->node,q2->node);
            scanf("%s",p->node);
            printf("ｙｅｓの項目は %s で良いですか y/n ",q1->node);
            c=getch();
            if (c=='Y' || c=='y'){      // 子の接続
                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (printf("\n続けますか y/n "), c=getch(),c=='Y' || c=='y');
    printf("\n");
}
struct tnode *talloc(void)            // 記憶領域の取得
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
