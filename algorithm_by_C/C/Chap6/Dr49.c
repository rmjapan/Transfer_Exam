/*
 * ---------------------------------
 *      式の木を用いた式の計算     *
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode {
    struct tnode *left;     // 左部分木へのポインタ
    int ope;                // 項目
    struct tnode *right;    // 右部分木へのポインタ
};

struct tnode *talloc(void);
struct tnode *gentree(struct tnode *,char *);
void postfix(struct tnode *);

void main(void)
{
    struct tnode *root;
    char expression[] = "53*64+2/-";
    root=NULL;
    root=gentree(root,expression);

    postfix(root);         // 式の計算
    printf("value=%d\n",root->ope);
}
struct tnode *gentree(struct tnode *p,char *w)  // 式の木の作成
{
    int n;

    n=strlen(w);
    p=talloc();                     // 文字列の終端をノードにする
    if ('0'<=w[n-1] && w[n-1]<='9')        // 定数のときは数値に変換
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                // 終端を除く
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    // 式の木の計算
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}
struct tnode *talloc(void)     // 記憶領域の取得
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
