// Problem Mod.2 P11 Regular Bracket Sequence
// Problem: https://codeforces.com/problemset/problem/26/B

#include <iostream>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  int count = 0;
  int openBrackets = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      openBrackets++;
    }

    if (s[i] == ')') {
      if (openBrackets > 0) {
        openBrackets--;
        count += 2;
      }
    }
  }

  cout << count;

  return 0;
}