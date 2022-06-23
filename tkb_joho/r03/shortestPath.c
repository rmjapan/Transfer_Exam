/**
 *    author:  shosei
 *    created: 28.03.2022 18:59:59
 **/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define NON -1
#define G_SIZE 5
#define Q_SIZE 100
#define ROOT -2
int G[G_SIZE][G_SIZE] = {{0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {1, 0, 0, 1, 0},
                         {0, 1, 0, 0, 1},
                         {0, 0, 1, 0, 0}};

int visited[G_SIZE];
int Q[Q_SIZE];
int Qf, Qr;

void initQ() {
  for (int i = 0; i < Q_SIZE; i++) Q[i] = 0;
  Qf = 0;
  Qr = 0;
}

void enqueue(int e) {
  if (Qr == Q_SIZE) {
    fprintf(stderr, "Error: queue overflow.\n");
    exit(1);
  }
  Q[Qr++] = e;
}

int dequeue() {
  if (Qf == Qr) {
    fprintf(stderr, "Error: queue underflow.\n");
    exit(1);
  }
  return Q[Qf++];
}

bool emptyQ() {
  if (Qf == Qr)
    return true;
  else
    return false;
}

int shortestPath1(int s, int t) {
  int depth = 0; //ノードsからtまでの深さ（経路長）

  for (int i = 0; i < G_SIZE; i++) visited[i] = NON;
  //全ての頂点の最短経路への値を未確定状態とする
  // NON->未確定　その他ー＞確定状態
  visited[s] = 0;
  //始点に0を入れる。
  // v[4]=0
  // visited[i]には始点sからノードiまでの最短経路長が格納される。

  initQ();

  enqueue(s);
  /// Qに始点を入れて
  // Qが空でない限り以下の処理を実行する。

  while (!emptyQ()) {
    int v = dequeue();
    /// 要素を取り出し。
    depth = visited[v];
    /// depthにvisited[v]までの経路長を格納する。

    if (v == t) return depth;

    //ノードvに繋がっているノードiまでの最短経路長を更新し確定
    //ノードvと繋がっていたノードiを次回の値の更新のためキューへ詰む
    for (int i = 0; i < G_SIZE; i++) {
      if (G[v][i] == 1 && visited[i] == NON) {
        visited[i] = depth + 1;

        enqueue(i);
      }
    }
  }
  return NON;
}


int shortestPath2(int s, int t) {
  int depth = 0;

  for (int i = 0; i < G_SIZE; i++) visited[i] = NON;
  //ROOT:出発点を表す特別な値
  visited[s] = ROOT; //changed
  initQ();
  enqueue(s);

  while (!emptyQ()) {
    int v = dequeue();
    //エラー処理：始点sからｔまでの経路が存在しているときに１を返す
    if (v == t) return 1; //changed
    for (int i = 0; i < G_SIZE; i++) {
      if (G[v][i] == 1 && visited[i] == NON) {
        //sからiへ行くために最後にvを通ったという情報のメモ
        visited[i] = v; //changed
        enqueue(i);
      }
    }
  }
  return NON;
}

//始点sからtまでの経路を表示する(tはshortestPath2の引数と同じもの)
void getPath(int t) {
  initQ();
  int v = t;
  enqueue(v);
  while (visited[v] != ROOT) {
    v = visited[v];
    enqueue(v);
  }
  printf("Path: ");
  for (int i = Qr - 1; i >= 0; i--) printf("%d ", Q[i]);
  printf("\n");
}

void show_visited() {
  for (int i = 0; i < G_SIZE; i++) printf("%d ", visited[i]);
  printf("\n");
}

int main() {
  int s = 3, t = 0;
  // printf("depth: %d\n", shortestPath1(4, 1));
  // show_visited();
  // if(shortestPath2(1, 0)!=1){
    // printf("経路が存在しません\n");
    // exit(1);
  // }
  if(shortestPath2(s, t)!=1){
    printf("経路が存在しません\n");
    exit(1);
  }
  show_visited();
  getPath(t);
  return 0;
}