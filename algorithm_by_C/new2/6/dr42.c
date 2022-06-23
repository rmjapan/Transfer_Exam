/**
 *    created by: shosei
 *    2022.06.20. 10:58:30
 **/
#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

#define nil -1
#define MaxSize 100

struct tnode {
  int left;
  char name[12];
  int right;
};

int sp = 8;  //ノードの格納現在位置
struct tnode a[MaxSize] = {{1, "Machilda", 2},  {3, "Candy", 4},
                           {5, "Rolla", nil},   {nil, "Ann", nil},
                           {6, "Emy", 7},       {nil, "Nancy", nil},
                           {nil, "Eluza", nil}, {nil, "Lisa", nil}};

int main() {
  char key[12];
  int p, old;

  printf("key:");
  scanf("%s", key);

  //挿入位置を探す
  p = 0;
  while (p != nil) {
    old = p;
    if (strcmp(key, a[p].name) <= 0)
      p = a[p].left;
    else
      p = a[p].right;
  }

  //dataを挿入
  a[sp].left = a[sp].right = nil;
  strcpy(a[sp].name, key);
  if(strcmp(key, a[old].name) <= 0)
    a[old].left = sp;
  else
    a[old].right = sp;
  sp++;

  for(int i = 0; i<sp; i++){
    printf("%5d %s %5d\n", a[i].left, a[i].name, a[i].right);
  }
  return 0;
}