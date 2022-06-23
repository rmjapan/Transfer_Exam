/**
 *    created by: shosei
 *    2022.05.17. 21:51:20
 **/
#include <stdio.h>
#include <stdlib.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);

int A[100][100];
int *visited;
int time = 1;
int d[100], f[100], sp_d = 0, sp_f = 0;

//隣接行列の生成, 0オリジン
void make_adjMatrix(int n) {
  int i, j;
  int u, k, v;

  // init
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) A[i][j] = 0;

  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    u--;
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      v--;
      A[u][v] = 1;
    }
  }
}

void print_matorix(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) printf(" ");
      printf("%d", A[i][j]);
    }
    printf("\n");
  }
}
//頂点は0オリジン
void DFS(int i, int n) {
  int j;
  visited[i] = 1;
  d[i] = time++;  //訪れた時間を記録
  for (j = 0; j < n; j++) {
    if (!visited[j] && A[i][j]) {
      DFS(j, n);
    }
  }
  f[i] = time++; //訪問が完了した時間
}

int main() {
  int n;
  scanf("%d", &n);
  make_adjMatrix(n);
  // visited init
  visited = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) visited[i] = 0;  // 0オリジン

  for(int i = 0; i<n; i++)
    if(!visited[i])
      DFS(i, n);

  //print_matorix(n);

  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", i + 1, d[i], f[i]);
  }
  return 0;
}