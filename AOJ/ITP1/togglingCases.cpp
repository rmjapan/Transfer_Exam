/**
 *    author:  shosei
 *    created: 31.01.2022 21:15:16
 **/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()

int main() {
  string s;
  getline(cin, s);
  for (int i = 0; i < (int)s.size(); i++) {
    if (isalpha(s[i])) {
      if (islower(s[i])) cout << (char)toupper(s[i]);
      if (isupper(s[i])) cout << (char)tolower(s[i]);
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  return 0;
}
// int main() {
//   int diff = 'A' - 'a';
//   char ch;
//   while (1) {
//     scanf("%c", &ch);       //空白・改行を含めて一文字読み込む
//     if (ch == '\n') break;  //読み込んだ文字が改行の時終了する
//     if ('a' <= ch && ch <= 'z')
//       ch = ch + diff;
//     else if ('A' <= ch && ch <= 'Z')
//       ch = ch - diff;
//     cout << ch;
//   }
//   cout << endl;
//   return 0;
// }
