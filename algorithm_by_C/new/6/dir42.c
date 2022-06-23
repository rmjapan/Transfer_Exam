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

int sp = 8;  //ノードの格納現在位置
int main() {
  struct tnode a[MaxSize] = {{1, "Machilda", 2},  {3, "Candy", 4},
                             {5, "Rolla", nil},   {nil, "Ann", nil},
                             {6, "Emy", 7},       {nil, "Nancy", nil},
                             {nil, "Eluza", nil}, {nil, "Lisa", nil}};
  char key[12];
  int p, old, i;

  while (printf("new data name --> "), scanf("%s", key) != EOF) {
    p = 0;
    while (p != nil) {  // search
      old = p;
      if (strcmp(key, a[p].name) <= 0)
        p = a[p].left;
      else
        p = a[p].right;
    }

    a[sp].right = a[sp].left = nil; //ノードの接続
    strcpy(a[sp].name, key);
    if (strcmp(key, a[old].name) <= 0)
      a[old].left = sp++;
    else
      a[old].right = sp++;
  }

  for (i = 0; i < sp; i++)
    printf("%4d%12s%4d\n", a[i].left, a[i].name, a[i].right);
  return 0;
}