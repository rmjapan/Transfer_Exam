//
//  main.c
//  h23(4)
//
//  Created by 水野桃夏 on 2020/04/23.
//  Copyright © 2020 水野桃夏. All rights reserved.
//

#include <stdio.h>
#define N 100
#define MAX 10000
// int a[N][N] = {{MAX, 10, 15, 40, MAX},
//                {10, MAX, 10, MAX, 50},
//                {15, 10, MAX, 30, 20},
//                {40, MAX, 30, MAX, 20},
//                {MAX, 50, 20, 20, MAX}};

int a[N][N] = {{MAX, 10, 15, 40, MAX},
               {10, MAX, 10, MAX, 50},
               {15, 10, MAX, 30, 20},
               {40, MAX, 30, MAX, -20},
               {MAX, 50, 20, -20, MAX}};
int checked[N];
int d[N];
int p[N];

int find_min(int n) {
  int min_node = -1;
  int min_dist = MAX;
  int i;
  for (i = 0; i < n; i++) {
    if (checked[i] == 0 && min_dist > d[i]) {
      min_dist = d[i];
      min_node = i;
    }
  }
  return min_node;
}

int f(int start, int end, int n) {
  int node, i;
  for (i = 0; i < n; i++) {
    checked[i] = 0;
    d[i] = MAX;
    p[i] = -1;
  }
  node = start;
  checked[node] = 1;
  d[node] = 0;
  while (1) {
    for (i = 0; i < n; i++) {
      if ((!checked[i]) && (d[i] > d[node] + a[node][i])) {
        d[i] = d[node] + a[node][i];
        p[i] = node;
      }
    }
    for (i = 0; i < n; i++) printf("%d ", d[i]);
    printf("\n");
    if ((node = find_min(n)) == -1) return -1;
    checked[node] = 1;
    if (node == end) return d[node];
  }
}

int main(int argc, const char* argv[]) {
  int i;
  printf("%d\n", f(0, 4, 5));
  printf("p : ");
  for (i = 0; i < 5; i++) printf("%d ", p[i]);
  return 0;
}