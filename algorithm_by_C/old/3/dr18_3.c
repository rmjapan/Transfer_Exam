/**
*    author:  shosei
*    created: 18.05.2021 23:00:51
**/
#include <stdio.h>
#include <string.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define N 10
int main()
{
  struct girl
  {
    char name[20];
    int age;
  } * t, *p[N], a[] = {"Ann", 18, "Rolla", 19, "Nancy", 16, "Eluza", 17, "Juliet", 18, "Machilda", 20, "Emy", 15, "Candy", 16, "Ema", 17, "Mari", 18};

  char *min;
  int s, i, j;
  for (i = 0; i < N;i++)
    p[i] = &a[i];

  for (i = 0; i < N;i++){
    min = p[i]->name;
    s = i;
    for (j = i + 1; j < N;j++){
      if(strcmp(p[j]->name,min)<0){
        min = p[j]->name;
        s = j;
      }
    }
    t = p[i];
    p[i] = p[s];
    p[s] = t;
  }

  for (i = 0; i < N;i++)
    printf("%10s%4d\n", p[i]->name, p[i]->age);

  return 0;
}
