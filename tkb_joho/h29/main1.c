#include <stdio.h>
#define N 7
#define MAX_SCORE 100

struct item {
  char id[8];
  int math;
  int eng;
};

void print_table(int size, int r[], struct item t[]) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d %s %d %d\n", i + 1, t[r[i]].id, t[r[i]].math, t[r[i]].eng);
  }
}

void swap(int r[], int i, int j) {
  int tmp;
  tmp = r[i];
  r[i] = r[j];
  r[j] = tmp;
}

int cmp(int i, int j, int r[], struct item t[]) {
  if (t[r[i]].math == t[r[j]].math)
    return t[r[i]].eng - t[r[j]].eng;
  else
    return t[r[i]].math - t[r[j]].math;
}

void make_ranking(int size, int r[], struct item t[]) {
  int i, j;
  for (i = 0; i < size; i++) r[i] = i;
  for (i = 0; i < size; i++) {
    for (j = size - 1; j > i; j--) {
      if (cmp(i, j, r, t) > 0) swap(r, i, j);
    }
  }
}

void make_ranking_m(int size, int r[], struct item t[]) {
  int count[MAX_SCORE + 1];
  int i;
  for (i = 0; i <= MAX_SCORE; i++) count[i] = 0;
  for (i = 0; i < size; i++) count[t[i].math]++;
  for (i = 1; i <= MAX_SCORE; i++) count[i] += count[i - 1];
  for (i = size - 1; i >= 0; i--) r[--count[t[i].math]] = i;
}


//基数ソート, 引数に作業用配列bが増えた
void make_ranking_radix(int size, int r[], struct item t[], struct item b[]) {
  int count[MAX_SCORE + 1];
  int i;
  //作業用配列bに英語でソートしたデータを入れる
  for (i = 0; i <= MAX_SCORE; i++) count[i] = 0;
  for (i = 0; i < size; i++) count[t[i].eng]++;
  for (i = 1; i <= MAX_SCORE; i++) count[i] += count[i - 1];
  for (i = size - 1; i >= 0; i--) b[--count[t[i].eng]] = t[i];
  //英語でソートしたデータについてランキングを作る
  for (i = 0; i <= MAX_SCORE; i++) count[i] = 0;
  for (i = 0; i < size; i++) count[b[i].math]++;
  for (i = 1; i <= MAX_SCORE; i++) count[i] += count[i - 1];
  for (i = size - 1; i >= 0; i--) r[--count[b[i].math]] = i;
}

int main(void) {
  struct item table[N] = {{"1", 30, 20},  {"2", 40, 10}, {"3", 30, 60},
                          {"4", 100, 50}, {"5", 80, 40}, {"6", 30, 40},
                          {"7", 30, 10}};
  struct item b[N]; //作業用配列
  int rank[N];
  int size = N;
  //make_ranking(size, rank, table);
  // make_ranking_m(size, rank, table);
  // print_table(size, rank, table);

  make_ranking_radix(size, rank, table, b);

  print_table(size, rank, b);

  return 0;
}