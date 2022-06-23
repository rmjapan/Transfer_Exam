/**
 *    author:  shosei
 *    created: 10.04.2022 14:24:25
 **/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 7

struct kv {
  char *key;
  int value;
} kv_array[N] = {{"ant", 120},   {"any", 260},    {"aneyway", 120},
                 {"apart", 380}, {"appear", 290}, {"apple", 190},
                 {"bad", 400}};

struct kv kv_array[N];

int search_array(char *key) {
  int start = 0, end = N - 1, middle;
  while (start <= end) {
    middle = start + (end - start) / 2;
    if (strcmp(kv_array[middle].key, key) == 0) {
      return middle;
    } else if (strcmp(kv_array[middle].key, key) < 0) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
  }
  return -1;
}

int main() {
  int index;
  if ((index = search_array("appear")) != -1) {
    printf("%s->%d\n", kv_array[index].key, kv_array[index].value);
  } else {
    printf("Not faund\n");
  }
  return 0;
}