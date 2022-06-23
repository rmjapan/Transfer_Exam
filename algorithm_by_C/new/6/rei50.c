/**
 *    author:  shosei
 *    created: 22.02.2022 17:31:55
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

#define Max 100
#define nil -1

int getch() {
  rewind(stdin);
  return getchar();
}

int main() {
  struct tnode {
    int left;
    char node[30];
    int right;
  };
  static struct tnode a[Max] = {{1, "芸能人ですか", 2}, {3, "歌手ですか", 4},
                                {nil, "吉田 茂", nil},  {nil, "井上 陽水", nil},
                                {5, "女優ですか", 6},   {nil, "中山 美穂", nil},
                                {nil, "久米 宏", nil}};
  int p,lp = 6, c;
  do{
    p=0;
    while(a[p].left !=nil){ //木のサーチ
      printf("\n%s y/n ",a[p].node); c = getch();
      if(c=='y' || c=='Y')
        p = a[p].left;
      else
        p = a[p].right;
    }
    printf("\n 答えは %s です.\n正しいですか y/n ",a[p].node);
    c=getch();
    if(c == 'n' || c=='N'){
      a[lp+1] = a[p]; //ノードの移動

      printf("\n あなたの考えは？");
      scanf("%s",a[lp+2].node);
      a[lp+2].left = a[lp+2].right = nil;

      printf("%s と %s を区別する質問は？ ",a[lp+1].node, a[lp+2].node);
      scanf("%s",a[p].node);
      printf("yes の項目は%sでイイですか？y/n ",a[lp+1].node);
      c=getch();

      if(c=='y'||c=='Y'){
        a[p].left = lp+1; a[p].right = lp+2;
      }else{
        a[p].left = lp+2; a[p].right = lp +1;
      }
      lp = lp + 2;
    }
  }while(printf("\n続けますか？ y/n "), c=getch(), c=='y' || c == 'Y');
  printf("\n");
  return 0;
}