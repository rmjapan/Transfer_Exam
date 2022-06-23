/**
 *    author:  shosei
 *    created: 18.02.2022 21:15:49
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define nil -1
#define MaxSize 100

struct tnode {
  int left;
  char name[12];
  int right;
};

int main() {
  struct tnode a[MaxSize] = {{1, "Machilda", 2},  {3, "Candy", 4},
                             {5, "Rolla", nil},   {nil, "Ann", nil},
                             {6, "Emy", 7},       {nil, "Nancy", nil},
                             {nil, "Eluza", nil}, {nil, "Lisa", nil}};
  char key[12];
  int p;
  printf("Search name --> ");
  scanf("%s", key);
  p = 0;
  while (p != nil) {
    if (strcmp(key, a[p].name) == 0) {
      printf("Found\n");
      break;
    } else if (strcmp(key, a[p].name) < 0)
      p = a[p].left;
    else
      p = a[p].right;
  }
  return 0;
}