/**
 *    author:  shosei
 *    created: 25.03.2022 16:18:12
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

struct person {
  char *name;
  struct plist *friends;
};

struct plist {
  struct person *data;
  struct plist *next;
};

struct pqueue {
  struct person *p;
  int value;
  struct pqueue *next;
};
struct pqueue *head, *tail;  //キューの末尾の要素(リストの最後)を指す

//人に番号を割り当てる
// ex) person[DAVE].name = Dave
enum { DAVE, BOB, ALICE, ELLEN, CAROL, FRANK };

//頂点に対応した会員の名前、および、友人の名前を画面に出力する
void print_person(struct person *);
// p1, p2が友人であることを示す辺をグラフに追加する
void become_friends(struct person *p1, struct person *p2);
//*plpが指すリストの先頭に要素pを追加する
void plist_add(struct plist **plp, struct person *p);
// 2名の会員の共通の友人を画面に表示する, 効率悪いほう
void print_common_friends(struct person *, struct person *);
//上を改善したもの、未実装
void print_common_friends_new(struct person *, struct person *);

//以下、(6)BFS用の関数
// p1と距離maxhop以下で繋がりがある会員p2をキューを使って幅優先で探索し、その範囲内で見つかれば1,見つからなければ0を返す
int access_ok(struct person *p1, struct person *p2, int maxhop);
//リストを開放する
void plist_free(struct plist *pl);
//リストplに要素pが含まれていたら1, 含まれていなければ0を返す。
int plist_contains(struct plist *pl, struct person *p);
// struct person*型の値、および、
//整数を保持するキューを割り当て、そのポインタを返す。
struct pqueue *pqueue_alloc();
//キューを解放する
void pqueue_free(struct pqueue *q);
//待ち行列qに要素p、および、nを追加する。
void pqueue_put(struct pqueue *q, struct person *p, int n);
/*
待ち行列qがからの時は、何もしないで0を返す
待ち行列qが空ではないときは、struct person *型と整数型の要素を取り出し、
それぞれを*ppと*npへセットする。結果として1を返す。
*/
int pqueue_get(struct pqueue *q, struct person **pp, int *np);

// access_okの実態、BFS
int access_ok1(struct person *p1, struct person *p2, struct plist **visited,
               struct pqueue *q, int maxhop);

int main(int argc, const char *argv[]) {
  int i, j;
  //初期化処理
  struct person person[N] = {{"Dave", NULL},  {"Bob", NULL},   {"Alice", NULL},
                             {"Ellen", NULL}, {"Carol", NULL}, {"Frank", NULL}};

  //過去問と同じグラフの生成,一度の処理で双方向に友人を追加できるため、辺の数だけ行えば十分なことに注意
  {
    become_friends(&person[DAVE], &person[BOB]);
    become_friends(&person[DAVE], &person[CAROL]);
    become_friends(&person[DAVE], &person[ELLEN]);
    become_friends(&person[BOB], &person[ALICE]);
    become_friends(&person[ALICE], &person[CAROL]);
    become_friends(&person[CAROL], &person[FRANK]);
    become_friends(&person[CAROL], &person[ELLEN]);
    become_friends(&person[FRANK], &person[ELLEN]);
  }
  // DAVEとBOBが友達になっているか調べる。
  //しっかり動作しているため,become_friendsおよびplist_addは正しく動作している
  //  become_friends(&person[DAVE], &person[BOB]);
  //  printf("%s\n", person[DAVE].friends->data->name);
  //  printf("%s\n", person[BOB].friends->data->name);

  //きちんとグラフが生成できているか、問1で作ったprint_personで確認
  //成功
  // for (i = 0; i < N; i++) {
  //   print_person(&person[i]);
  // }

  //共通の友人を出力
  //成功
  // for (i = 0; i < N; i++) {
  //   for (j = i + 1; j < N; j++) {
  //     print_common_friends(&person[i], &person[j]);
  //   }
  // }
  // if (access_ok(&person[DAVE], &person[BOB], 3))
  //   printf("OK");
  // else
  //   printf("NG");

  //テスト用　OK
  // struct pqueue *q = pqueue_alloc();
  // struct person *p;
  // int np;
  // head = tail = q;
  // pqueue_put(q, &person[DAVE], 1);
  // pqueue_put(q, &person[ALICE], 2);
  // if (pqueue_get(q, &p, &np)) printf("%s %d\n", p->name, np);
  // if (pqueue_get(q, &p, &np)) printf("%s %d\n", p->name, np);

  // OK
  //  if (plist_contains(person[DAVE].friends, &person[FRANK]))
  //    printf("YES");
  //  else
  //    printf("NO");

  // access_okの確認
  //参考：maxhop=1のときは友人のみを招待している．
  for (i = 0; i < N; i++) {
    printf("%s:\n", person[i].name);
    for (j = 0; j < N; j++) {
      if (i == j) continue;
      if (access_ok(&person[i], &person[j], 1)) {
        printf("\t%5s:OK\n", person[j].name);
      } else {
        printf("\t%5s:NG\n", person[j].name);
      }
    }
    printf("\n");
  }

  return 0;
}

void print_person(struct person *p) {
  printf("Name: %s, friends: { ", p->name);
  for (struct plist *pl = p->friends; pl != NULL; pl = pl->next)
    printf("%s, ", pl->data->name);
  printf("}\n");
}

void plist_add(struct plist **plp, struct person *p) {
  struct plist *pl;
  if ((pl = (struct plist *)malloc(sizeof(struct plist))) == NULL)
    printf("メモリが足らない\n");
  pl->next = *plp;
  *plp = pl;
  pl->data = p;
}

void become_friends(struct person *p1, struct person *p2) {
  plist_add(&(p1->friends), p2);
  plist_add(&(p2->friends), p1);
}

void print_common_friends(struct person *p1, struct person *p2) {
  struct plist *pl1, *pl2;
  printf("%s and %s have common friends: { ", p1->name, p2->name);
  for (pl1 = p1->friends; pl1 != NULL; pl1 = pl1->next) {
    for (pl2 = p2->friends; pl2 != NULL; pl2 = pl2->next) {
      if (strcmp(pl1->data->name, pl2->data->name) == 0)
        printf("%s, ", pl1->data->name);
    }
  }
  printf("}\n");
}

int access_ok1(struct person *p1, struct person *p2, struct plist **visited,
               struct pqueue *q, int maxhop) {
  struct person *p;
  int hop;
  pqueue_put(q, p1, 0);  //待ち行列qにp1と0を追加する
  while (pqueue_get(q, &p,
                    &hop)) {  //待ち行列からstruct person *と整数を取り出す。

    plist_add(visited, p);  //頂点pを訪問した
    if (hop > maxhop) return 0;
    if (p == p2) return 1;
    for (struct plist *pl = p->friends; pl != NULL; pl = pl->next) {
      struct person *f = pl->data;
      if (!plist_contains(*visited, f)) pqueue_put(q, f, hop + 1);
    }
  }
  return 0;
}

int access_ok(struct person *p1, struct person *p2, int maxhop) {
  struct plist *visited = NULL;       //空のリストを作成する
  struct pqueue *q = pqueue_alloc();  //待ち行列を割り当てる
  head = tail = q;                    // tailを初期化, changed
  int result = access_ok1(p1, p2, &visited, q, maxhop);
  pqueue_free(q);       //キューを解放する
  plist_free(visited);  //リストを解放する
  return result;
}

void plist_free(struct plist *pl) {
  struct plist *q;
  while (pl != NULL) {
    q = pl->next;  //次へのポインタを保存
    free(pl);
    pl = q;  //ポインタの更新
  }
}

int plist_contains(struct plist *pl, struct person *p) {
  for (struct plist *q = pl; q != NULL; q = q->next) {
    if (q->data == p) return 1;
  }
  return 0;
}

struct pqueue *pqueue_alloc() {
  struct pqueue *q;
  if ((q = (struct pqueue *)malloc(sizeof(struct pqueue))) == NULL)
    printf("メモリが足らない\n");
  return q;
}

void pqueue_free(struct pqueue *q) {
  struct pqueue *p;
  while (q != NULL) {
    p = q->next;
    free(q);
    q = p;
  }
}

void pqueue_put(struct pqueue *q, struct person *p, int n) {
  struct pqueue *cell = pqueue_alloc();

  //データ割り当て
  cell->value = n;
  cell->p = p;
  cell->next = NULL;

  //リストへつなぐ
  tail->next = cell;
  tail = cell;
}

int pqueue_get(struct pqueue *q, struct person **pp, int *np) {
  struct pqueue *old;
  if (q == tail) return 0;  //待ち行列qが空のとき

  old = head;
  //ダミーノード対策,
  // tailが最後の要素を指しているので自然とダミーノードが生まれる．多分頑張れば無くせるけど放置
  *pp = head->next->p;
  *np = head->next->value;
  head = head->next;  //次の要素を指すように変更
  // free(old);　//なんか知らんけどバグる
  return 1;
}