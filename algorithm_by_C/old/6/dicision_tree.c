#include <stdio.h>
#include <stdlib.h>

#define Max 100
#define nil -1

struct tnode
{
    struct tnode *left;
    char node[30];
    struct tnode *right;
};

struct tnode talloc()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

int getch(void)
{
    rewind(stdin);
    return getchar();
}

int main()
{
    struct tnode *root, *p, *q1, *q2;
    int c;

    root = talloc();
    printf("初期ノード？");
    scanf("%s", root->node);
    root->left = root->right = NULL;

    do
    {
        p = root;
        while (p->left != NULL)
        {
            printf("\n%s y/n", p->node);
            c = getch();
            if (c == 'y' || c == 'Y')
                p = p->left;
            else
                p = p->right;
        }

    } while (printf("\n続けますか？　y/n"), c = getch(), c == 'y' || c == 'Y');
    printf("\n");
}
