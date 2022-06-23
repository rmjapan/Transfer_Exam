/**
 *    created by: shosei
 *    03.06.2022 14:32:36
 **/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pra(ans) printf("%d\n", ans);
#define MAX 1400

struct Rectangle {
  int height;
  int pos;
};

int getLargestRectangle(int size, int buffer[]) {
  stack<Rectangle> S;
  int maxv = 0;
  buffer[size] = 0;  //番兵, 高さ0が最後にあればすべて回収できる

  for (int i = 0; i <= size; i++) {
    Rectangle rect;
    rect.height = buffer[i];
    rect.pos = i;
    if (S.empty()) {
      S.push(rect);
    } else {
      if (rect.height > S.top().height) {
        S.push(rect);
      } else if (rect.height < S.top().height) {
        int target = i;  //最後にスタックから取り出したpos
        while (!S.empty() && S.top().height >= rect.height) {
          Rectangle pre = S.top();
          S.pop();
          int area = pre.height * (i - pre.pos);
          maxv = max(maxv, area);
          target = pre.pos;
        }
        rect.pos = target;
        S.push(rect);
      }
    }
  }
  return maxv;
}

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle() {
  //テーブルTを生成
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (buffer[i][j]) {
        T[i][j] = 0;
      } else {
        T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
      }
    }
  }

  int maxv = 0;
  for (int i = 0; i < H; i++) {
    maxv =
        max(maxv, getLargestRectangle(
                      W, T[i]));  // i行目を送ってその戻り値とmaxvの大きいほう
  }
  return maxv;
}

int main() {
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &buffer[i][j]);
    }
  }
  cout << getLargestRectangle() << endl;
  return 0;
}