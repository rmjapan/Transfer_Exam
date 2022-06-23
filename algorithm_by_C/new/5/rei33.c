/**
 *    author:  shosei
 *    created: 14.02.2022 18:05:14
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
#define MaxSize 100

int queue[MaxSize];
int head = 0, tail = 0;

int enqueue(int a) {
  if (head == (tail + 1) % MaxSize)
    return -1;
  else {
    queue[tail % MaxSize] = a;
    tail++;
    return 0;
  }
}

int dequeue(int *a) {
  if (head == tail)
    return -1;
  else {
    *a = queue[head % MaxSize];
    head++;
    return 0;
  }
}

void disp(void) {
  int i;
  i = head;
  while (i != tail) {
    printf("%d\n", queue[i]);
    i++;
    i = i % MaxSize;
  }
}

int main() {
  int c, n;
  while (printf("]"), (c = getchar()) != EOF) {
    // rewind(stdin);
    switch (c) {
      case 'i':
        printf("data-> ");
        scanf("%d", &n);
        rewind(stdin);
        if (enqueue(n) == -1) printf("queue is full\n");
        break;
      case 'o':
        if (dequeue(&n) == -1)
          printf("queue is empty\n");
        else
          printf("queue data --> %d\n", n);
        break;
      case 'l':
        disp();
        break;
      default:
        break;
    }
  }
  return 0;
}