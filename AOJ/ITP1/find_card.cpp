/**
 *    author:  shosei
 *    created: 29.01.2022 23:14:56
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()

// cardを0で初期化
void set_card(char suit, map< char, vector< int > > &card) {
  rep(i, 13) { card[suit].push_back(0); }
}

void change_suit(char &suit) {
  static int cnt = 0;  //呼び出し回数の制御
  switch (cnt++) {
    case 0:
      suit = 'S';
      break;
    case 1:
      suit = 'H';
      break;
    case 2:
      suit = 'C';
      break;
    case 3:
      suit = 'D';
      break;
    default:
      cout<<"this suit doesn't exist.";
      break;
  }
}

int main() {
  int n;
  char suit;
  int rank;
  cin >> n;
  map< char, vector< int > > card;
  //初期設定
  set_card('S', card);
  set_card('H', card);
  set_card('C', card);
  set_card('D', card);
  rep(i, n) {
    cin >> suit >> rank;
    card[suit][rank - 1]++;
  }

  for (int i = 0; i < 4; i++) {
    change_suit(suit);  //絵柄の変更
    for (int j = 0; j < 13; j++) {
      if (card[suit][j] == 0) cout << suit << " " << j + 1 << endl;
    }
  }
  return 0;
}