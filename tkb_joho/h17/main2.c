#include <stdio.h>
#include <stdlib.h>

enum node_type { OP, NUM };
enum operation { ADD, SUB, MUL, DIV };

struct node {
  enum node_type type;
  int val;
  enum operation op;
  struct node *left;
  struct node *right;
};

//新たな親ノードを作り，leftとrightに指定したノードをつなぐ
struct node *make_node(enum node_type type, int op, int val, struct node *left,
                       struct node *right) {
  struct node *p;
  p = (struct node *)malloc(sizeof(struct node));
  p->type = type;
  p->op = op;
  p->val = val;
  p->left = left;
  p->right = right;
  return p;
}

#define MAKE_OP(op, l, r) make_node(OP, (op), 0, (l), (r))
#define MAKE_NUM(n) make_node(NUM, 0, (n), 0, 0)

//演算子ノードを出力
void print_op(struct node *p) {
  switch (p->op) {
    case ADD:
      printf("+");
      break;
    case SUB:
      printf("-");
      break;
    case MUL:
      printf("*");
      break;
    case DIV:
      printf("/");
      break;
    default:
      printf("?");
      break;
  }
}

void print_tree(struct node *p) {
  if (p->type == OP) {
    printf("(");
    print_tree(p->left);
    print_op(p);
    print_tree(p->right);
    printf(")");
  } else {
    printf("%d", p->val);
  }
}

// void print_tree2(struct node *p) {
//   if (p->type == OP) {
//     print_tree2(p->left);
//     print_tree2(p->right);
//     print_op(p);
//   } else {
//     printf(" %d", p->val);
//   }
// }

void print_tree2(struct node *p) {
  if (p->type == OP) {
    print_tree2(p->left);
    printf(" ");
    print_tree2(p->right);
    print_op(p);
  } else {
    printf("%d", p->val);
  }
}

int get_height(struct node *p) {
  int l_height, r_height;
  if (p->type == OP) {
    l_height = get_height(p->left);
    r_height = get_height(p->right);
    return (l_height > r_height) ? (l_height + 1) : (r_height + 1);
  } else {
    return 1;  //一番下の葉の高さは１
  }
}

int main() {
  struct node *n1, *n2, *n3, *n4, *n5;
  n1 = MAKE_NUM(1);
  n2 = MAKE_NUM(10);
  n3 = MAKE_NUM(100);
  n4 = MAKE_OP(ADD, n1, n2);
  n5 = MAKE_OP(MUL, n3, n4);
  print_tree2(n5);
  printf("\n%d", get_height(n5));
  printf("\n");
  return 0;
}