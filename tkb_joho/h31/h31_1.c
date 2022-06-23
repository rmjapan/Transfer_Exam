#include <stdio.h>
#define X_SIZE 7
#define Y_SIZE 5
int maze[X_SIZE][Y_SIZE] = {
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}};

int dist[X_SIZE][Y_SIZE];

int ok(int x, int y)
{
  if (maze[x][y] == 0)
    return 1;
  else
    return 0;
}

void init_dist(void)
{
  int x, y;
  for (y = 0; y < Y_SIZE; y++)
    for (x = 0; x < X_SIZE; x++)
      dist[x][y] = X_SIZE * Y_SIZE;
}

int update_dist(int x1, int y1, int x2, int y2)
{
  if (ok(x1, y1) && ok(x2, y2) && dist[x2][y2] > dist[x1][y1] + 1)
  {
    dist[x2][y2] = dist[x1][y1] + 1;
    return 1;
  }
  return 0;
}

int main(void)
{
  int changed, x, y;
  init_dist();
  dist[1][0] = 0;
  int count = 0;

  do
  {
    changed = 0;
    for (y = 0; y < Y_SIZE - 1; y++)
      for (x = 0; x < X_SIZE; x++)
      {
        changed += update_dist(x, y, x - 1, y) + update_dist(x, y, x + 1, y) + update_dist(x, y, x, y - 1) + update_dist(x, y, x, y + 1);
      }
    count++;
  } while (changed);
  for (y = 0; y < Y_SIZE; y++)
  {
    for (x = 0; x < X_SIZE; x++)
    {
      printf("%2d,", dist[x][y]);
    }
    printf("\n");
  }
  printf("%d", count);
  return 0;
}