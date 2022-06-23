/**
 *    author:  shosei
 *    created: 24.04.2022 18:09:50
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 4  //グラフのノードの数

struct node {
  int adjacent;
  struct node *next;
};

int count1 = 0;  //テスト用

/*
id:ノード番号
visited[]:既に訪れたノード
nodes:グラフを表現した配列
 */
void visit(int id, int visited[], struct node nodes[]) {
  struct node *n;
  if (visited[id]) return;
  visited[id] = 1;
  for (n = &nodes[id]; n->adjacent != -1; n = n->next) {  // DFS
    visit(n->adjacent, visited, nodes);
    count1++;
  }
}

/*
nnode:頂点数
nodes:グラフを表現した配列
*/
int is_connected(int nnode, struct node nodes[]) {
  int i, *visited;
  visited = (int *)malloc(sizeof(int) * nnode);
  for (i = 0; i < nnode; i++) visited[i] = 0;
  visit(0, visited, nodes);
  count1++;

  for (i = 0; i < nnode; i++)
    if (visited[i] == 0)  //訪れていないノードがあれば0
      return 0;
  return 1;  //全てのノードを訪れていたら1
}

/*
nnode:頂点数
nodes:グラフを表現した配列
*/
int is_euler(int nnode, struct node nodes[]) {
  int i, j, count = 0;
  struct node *n;
  if (!is_connected(nnode, nodes)) return 0;  //連結でない時一筆書きは出来ない

  for (i = 0; i < nnode; i++) {
    n = nodes[i].next;
    j = 0;
    while (n != NULL) {  // nodes[i]に接続している辺の数jを調べる
      j++;
      n = n->next;
    }

    if (j % 2 == 1)
      count++;  //グラフGの頂点のうち，接続している辺の本数が奇数であるものの個数をcountへ加算
  }
  return (count == 0) || (count == 2);
}

// vが指すリストにノードv_idを追加する
void add_node(int id, struct node *v) {
  struct node *v1;
  if ((v1 = (struct node *)malloc(sizeof(struct node))) == NULL) {
    printf("メモリ不足");
    exit(1);
  }
  v1->adjacent = id;  //追加するノード
  v1->next = v->next;
  v->next = v1;
}

int main() {
  // struct node nodes[N] = {{1, NULL}, {3, NULL}, {3, NULL}, {2, NULL}};
  // struct node *sentinel = (struct node *)malloc(sizeof(struct node));  //番兵
  // sentinel->adjacent = -1;
  // sentinel->next = NULL;
  // for (int i = 0; i < N; i++) {
  //   nodes[i].next = sentinel;  //初期化
  // }

  // {  // G1の生成
  //   //
  //   add_nodeを少し変えて，nodes[i].nextを渡しても良い．個人的にこちらが好きなのでこのままにしておく
  //   add_node(0, &nodes[1]);
  //   add_node(2, &nodes[1]);
  //   add_node(1, &nodes[2]);
  //   add_node(1, &nodes[3]);
  // }

  //一筆書き出来ないグラフの生成
  struct node nodes[N] = {{1, NULL}, {2, NULL}, {3, NULL}, {0, NULL}};
  struct node *sentinel = (struct node *)malloc(sizeof(struct node));  //番兵
  sentinel->adjacent = -1;
  sentinel->next = NULL;
  for (int i = 0; i < N; i++) {
    nodes[i].next = sentinel;  //初期化
  }

  {
    add_node(2, &nodes[0]);
    add_node(3, &nodes[0]);
    add_node(0, &nodes[1]);
    add_node(3, &nodes[1]);
    add_node(1, &nodes[2]);
    add_node(0, &nodes[2]);
    add_node(1, &nodes[3]);
    add_node(2, &nodes[3]);
  }

  // 隣接リストの表示
  for (int i = 0; i < N; i++) {
    printf("v[%d] -> ", i);
    for (struct node *v = &nodes[i]; v->adjacent != -1; v = v->next)
      printf("v[%d]->", v->adjacent);
    printf("[]\n");
  }

  //(1)用
  // if (is_connected(N, nodes))
  //   printf("連結\n");
  // else
  //   printf("連結でない\n");

  //(3)用
  // y=4
  // is_connected(N, nodes);
  // printf("y = %d\n", count1);

  //(4)

  if (is_euler(N, nodes))
    printf("OK\n");
  else
    printf("NG\n");

  return 0;
}