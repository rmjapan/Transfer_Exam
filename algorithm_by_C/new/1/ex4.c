/**
 *    author:  shosei
 *    created: 26.01.2022 22:48:50
 **/
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define N 20
//１～Nの乱数を一つ得る
// intへキャストしたときに最大nになるように調整している
// ex) rand()=1のとき、全体はn+1にやや満たない整数になり、整数部分だけが残るから結果としてnが残る
int irnd(int n)
{
  return (int)((rand() / (RAND_MAX + 0.1)) * n + 1);
}

int main()
{
  srand((unsigned int)time(NULL));//set rand:現在時刻を符号なしで返しているイメージ
  int a[N + 1];
  a[1] = irnd(N);

  int flag;
  for (int i = 2; i <= N; i++)
  {
    do
    {
      a[i] = irnd(N);
      flag = 0;
      for (int j = 1; j < i; j++)
        if(a[i] == a[j]){
          flag = 1;
          break;
        }

    } while (flag == 1);
  }

  for (int i = 1; i <= N; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}