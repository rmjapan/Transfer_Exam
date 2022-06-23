/**
 *    author:  shosei
 *    created: 17.02.2022 22:24:56
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vii = vector<vi>;

struct Node {
  int key;
  struct Node *next, *prev;
};

Node *head;

Node *talloc() { return (Node *)malloc(sizeof(Node)); }

//リストの初期化。
void init() {
  head = talloc();
  head->next = head;
  head->prev = head;
}

void insert(int key) {
  Node *x = talloc();
  x->key = key;
  //番兵の後に要素を追加
  x->next = head->next;
  head->next->prev = x;
  head->next = x;
  x->prev = head;
}
Node *listSearch(int key) {
  Node *cur = head->next;
  while (cur != head && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t) {
  if (t == head) return;  // tが番兵の場合は処理しない
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() { deleteNode(head->next); }

void deleteLast() { deleteNode(head->prev); }

void deleteKey(int key) { deleteNode(listSearch(key)); }

void printList() {
  Node *p;

  p = head->next;
  while (p != head) {
    if (p != head->next) printf(" ");
    printf("%d", p->key);
    p = p->next;
  }
  printf("\n");
}

int main() {
  int n, key, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;  // num of delete or plus
  scanf("%d", &n);
  init();
  for (i = 0; i < n; i++) {
    scanf("%s", com);
    if (com[0] == 'i') {
      scanf("%d", &key);
      insert(key);
      np++;
      size++;
    } else if (com[0] == 'd') {
      if (strlen(com) > 6) {
        if (com[6] == 'F')
          deleteFirst();
        else if (com[6] == 'L')
          deleteLast();
      } else {
        scanf("%d", &key);
        deleteKey(key);
        nd++;
      }
      size--;
    }
    rewind(stdin);
  }
  printList();
  return 0;
}