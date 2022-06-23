/*
 * -----------------------------------------------
 *      レベルごとの２分探索木のトラバーサル     *
 * -----------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     // 左部分木へのポインタ
    char name[12];          // 名前
    struct tnode *right;    // 右部分木へのポインタ
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void treewalk(struct tnode *);

void main(void)
{
    char dat[12];
    struct tnode *root;

    root=NULL;
    while (scanf("%s",dat)!=EOF){
        root=gentree(root,dat);
    }
    treewalk(root);
}
void treewalk(struct tnode *p)  // レベルごとの木のトラバーサル
{
    struct tnode *q[128],       // ポインタ・テーブル
                 *w[128];       // 作業用
    int i,child,n,level;

    child=1; q[0]=p; level=0;   // 初期値
    do {
        n=0;
        printf("level %d :",level);
        for (i=0;i<child;i++){
            printf("%12s",q[i]->name); // ノードの表示
            // １つ下のレベルの子へのポインタをスタックに積む
            if (q[i]->left!=NULL)
                w[n++]=q[i]->left;
            if (q[i]->right!=NULL)
                w[n++]=q[i]->right;
        }
        printf("\n");
        child=n;            // １つ下のレベルの子の数
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}
struct tnode *gentree(struct tnode *p,char *w)  // 木の作成の再帰手続き
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}
struct tnode *talloc(void)     // 記憶領域の取得
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
