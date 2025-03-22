// Module 2: Yet Another Broken Keyboard (1907B)
// Problem: https://codeforces.com/problemset/problem/1907/B

#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    string s;
    cin >> s;

    int size = s.length();
    stack<int> lowerPos;
    stack<int> upperPos;
    unordered_map<int, bool> toSkip;

    for (int i = 0; i < size; i++) {
      if (s[i] != 'b' && s[i] != 'B') {
        if (isupper(s[i])) upperPos.push(i);
        if (islower(s[i])) lowerPos.push(i);
      }

      if (s[i] == 'b' && !lowerPos.empty()) {
        int top = lowerPos.top();
        toSkip[top] = true;
        lowerPos.pop();
      }

      if (s[i] == 'B' && !upperPos.empty()) {
        int top = upperPos.top();
        toSkip[top] = true;
        upperPos.pop();
      }
    }

    for (int i = 0; i < size; i++) {
      if (toSkip[i] || s[i] == 'b' || s[i] == 'B') {
        continue;
      }
      cout << s[i];
    }

    cout << endl;

    cases--;
  }

  return 0;
}