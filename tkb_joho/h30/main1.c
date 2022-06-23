#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dt {
    int student;
    char course[20];
    int score;
    struct dt *next;
};

struct dt *head;

void load_file()
{
    FILE *file = fopen("data.txt", "r");
    int s;
    char c[20];
    int sc;

    head = NULL;

    while (fscanf(file, "%d %s %d", &s, c, &sc) != EOF) {
        struct dt *new;
        new = (struct dt *) malloc(sizeof(struct dt));
        new->student = s;
        strcpy(new->course, c);
        new->score = sc;

        new->next = head; //データを後ろから格納している
        head = new; //newの先頭アドレスを格納
    }
}

void remove_one(struct dt *d)
{
    struct dt *p, *prev;

    if (head == d){ //先頭に対する処理、これをやらないとprevが使えない
        head = d->next;
        return;
    }

    prev = head;
    for (p = head->next; p != NULL; prev = p, p = p->next) {
        if (p == d){
            prev->next = d->next;
            return;
        }
    }
}

void sort_list()
{
    struct dt *p;
    struct dt *min = head;//先頭を最小値にする

    if (head == NULL) { //全部取り除かれたときに実行
        return;
    }

    for (p = head->next; p !=NULL; p = p->next){//最小値を求める
        if (min->student > p->student) {
            min = p;
        }
    }

    remove_one(min);
    sort_list(); //再呼び出し
    min->next = head; //最後の取り出された最小値は各ループ内の最大値になっている、つまり昇順に並ぶ
    head = min;
}

void print_avarage()
{
    int count = 0, total = 0;
    struct dt *p;

    for (p = head; p != NULL; p = p ->next) {
        if (p->next != NULL && p->student == p->next->student)
        {
            count++;
            total += p->student;
        }
        else
        {
            count++;
            total += p->student;
            printf("%d %d %d\n", p->student, count, total / count);
            count = 0;
            total = 0;
        }
    }
}

int main(void)
{
    load_file();
    sort_list();
    print_avarage();

    return 0;
}