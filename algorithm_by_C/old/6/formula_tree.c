/**
*    author:  shosei
*    created: 27.06.2021 22:08:46
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tnode
{
    struct tnode *right;
    struct tnode *left;
    char ope;
};

struct tnode *talloc();
struct tnode *gentree(struct tnode *, char *);
// void prefix(struct tnode *);
// void infix(struct tnode *);
// void postfix(struct tnode *);
void postfix(struct tnode *);

int main()
{
    struct tnode *root;
    char expression[] = "53*64+2/-";

    root = NULL;
    root = gentree(root, expression);

    postfix(root);
    printf("value = %d\n", root->ope);
    return 0;
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *gentree(struct tnode *p, char *w)
{
    int n;

    n = strlen(w);
    p = talloc();
    if ('0' <= w[n - 1] && w[n - 1] <= '9')
        p->ope = w[n - 1] - '0'; //文字列の終端をノードにする
    else
        p->ope = w[n - 1];
    w[n - 1] = '\0'; //終端を除く
    if (!(p->ope == '-' || p->ope == '+' || p->ope == '*' || p->ope == '/'))
    {
        p->left = p->right = NULL;
    }
    else
    {
        p->right = gentree(p->right, w);
        p->left = gentree(p->left, w);
    }
    return p;
}

void postfix(struct tnode *p)
{
    if (p != NULL)
    {
        postfix(p->left);
        postfix(p->right);
        switch (p->ope)
        {
        case '-':
            p->ope = (p->left->ope) - (p->right->ope);
            break;
        case '+':
            p->ope = (p->left->ope) + (p->right->ope);
            break;
        case '*':
            p->ope = (p->left->ope) * (p->right->ope);
            break;
        case '/':
            p->ope = (p->left->ope) / (p->right->ope);
            break;
        }
    }
}

// void prefix(struct tnode *p)
// {
//     if (p != NULL)
//     {
//         putchar(p->ope);
//         prefix(p->left);
//         prefix(p->right);
//     }
// }
// void infix(struct tnode *p)
// {
//     if (p != NULL)
//     {
//         infix(p->left);
//         putchar(p->ope);
//         infix(p->right);
//     }
// }

// void postfix(struct tnode *p)
// {
//     if (p != NULL)
//     {
//         postfix(p->left);
//         postfix(p->right);
//         putchar(p->ope);
//     }
// }
