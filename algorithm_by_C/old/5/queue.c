/**
*    author:  shosei
*    created: 13.06.2021 16:13:47
**/
#include <stdio.h>

#define MaxSize 100
int queue[MaxSize];
int head = 0, tail = 0;

int queuein(int);
int queueout(int *);
void disp();

int main()
{
  char c;
  int n;
  while (printf("]"), (c = getchar()) != EOF)
  {
    rewind(stdin);
    if (c == 'i' || c == 'I')
    {
      printf("data-->");
      scanf("%d", &n);
      rewind(stdin);
      if (queuein(n) == -1)
        printf("キューがいっぱいです\n");
    }
    if (c == 'o' || c == 'O')
    {
      if (queueout(&n) == -1)
        printf("キューは空です\n");
      else
        printf("queue data --> %d\n", n);
    }

    if (c == 'l' || c == 'L')
    {
      disp();
      break;
    }
  }
  return 0;
}

int queuein(int n)
{
  if ((tail + 1) % MaxSize != head)
  {
    queue[tail] = n;
    tail++;
    tail = tail % MaxSize; //modを使えばリング状の配列が表現できる
    return 0;
  }
  else
  {
    return -1;
  }
}

int queueout(int *n)
{
  if (tail != head)
  {
    *n = queue[head];
    head++;
    head = head % MaxSize;
    return 0;
  }
  else
  {
    return -1; //キューが空の時
  }
}

void disp()
{
  for (head; tail > head; head++)
  {
    printf("%d ", queue[head]);`  
    head = head % MaxSize;
  }
}
