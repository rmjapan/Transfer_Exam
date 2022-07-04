#include <stdio.h>
#include <string.h>
#define NUMBER 3
#define NAME_LEN 64

typedef struct {
  char name[NAME_LEN];
  int height;
} Student;

void swap_Student(Student *x, Student *y) {
  Student temp = *x;
  *x = *y;
  *y = temp;
}

void sort_height(Student a[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; j > i; j--)
      if (a[j - 1].height > a[j].height) swap_Student(&a[j - 1], &a[j]);
  }
}

int main() {
  int i;
  Student std[] = {
      {"Mike", 179},
      {"Tom", 190},
      {"Kate", 165},
  };

  sort_height(std, NUMBER);
  for (i = 0; i < NUMBER; i++) printf("%s, %d\n", std[i].name, std[i].height);
  return 0;
}