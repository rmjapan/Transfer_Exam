/**
 *    author:  shosei
 *    created: 08.02.2022 02:26:07
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int a, b;
  stack<int> stack;  //スタック
  char op[10];

  while (scanf("%s", op) != EOF) {
    if (isdigit(op[0])) {
      stack.push(stoi(op));
    } else {
      switch (op[0]) {
        case '+':
          b = stack.top();
          stack.pop();
          a = stack.top();
          stack.pop();
          stack.push(a + b);
          break;
        case '-':
          b = stack.top();
          stack.pop();
          a = stack.top();
          stack.pop();
          stack.push(a - b);
          break;
        case '*':
          b = stack.top();
          stack.pop();
          a = stack.top();
          stack.pop();
          stack.push(a * b);
          break;
        case '/':
          b = stack.top();
          stack.pop();
          a = stack.top();
          stack.pop();
          stack.push(a / b);
          break;
        case ' ':
        case '\t':
          break;
        default:
          break;
      }
    }
  }
  cout << stack.top() << endl;
  return 0;
}