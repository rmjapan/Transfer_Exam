/*
流れ
1. 隣接リストの生成
2. 双方向のリンクがある場合についてのDFS
*/

/**
 *    created by: shosei
 *    2022.05.20. 14:42:10
 **/
#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

#define N 1000000
int *visited;

struct node {
  int id;
  struct node *next;
} * A[N];

//A[i]にノードjをつなぐ
void become_friend(int i, int j) {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  p->id = j;
  p->next = A[i];
  A[i] = p;
}

//隣接リストの生成
void Make_adjlist(int n, int m) {
  int s, t;

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &s, &t);

    become_friend(s,t);  // sを要素として持つノードをpをA[s]につなげる
    become_friend(t,s);
  }
}

int is_reachable(int s, int t, int n) {
  int j;
  visited[s] = 1;
  if (s == t) return 1;  //到達可能

  for (struct node *p = A[s]; p != NULL; p = p->next) {
    if (!visited[p->id]) {
      if (is_reachable(p->id, t, n)) return 1;  // jからtへ到達可能
    }
  }
  return 0;
}

void print_list(int n) {
  int i, j;

  for (int i = 0; i < n; i++) {
    printf("%d : {", i);
    for (struct node *p = A[i]; p != NULL; p = p->next) {
      printf("%d->", p->id);
    }
    printf("[] }\n");
  }
}

int main() {
  int i, j;
  int n, m;
  int s, t, q;
  scanf("%d %d", &n, &m);

  // init, input
  visited = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) A[i] = NULL;  //初期化

  Make_adjlist(n, m);

  //print_list(n);

  //処理
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    for (j = 0; j < n; j++) visited[j] = 0;  //毎回初期化

    scanf("%d %d", &s, &t);
    if (is_reachable(s, t, n))
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}