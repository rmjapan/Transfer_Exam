void shiftdown(int p, int n, int heap[]) {
  int s;
  s = 2 * p;
  while (s <= n) {
    if (s < n && heap[s + 1] < heap[s]) s++;
    if (heap[p] <= heap[s]) break;
    swap(&heap[p], &heap[s]);
    p = s;
    s = 2 * p;
  }
}