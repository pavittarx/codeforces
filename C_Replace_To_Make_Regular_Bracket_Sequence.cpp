// 612C Mod.2 P12 Replace to Make Regular Bracket Sequence
// Problem: https://codeforces.com/problemset/problem/612/C

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  int count = 0;
  stack<char> st;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '<' || s[i] == '(' || s[i] == '{' || s[i] == '[') {
      st.push(s[i]);
      continue;
    }

    if (st.empty()) {
      count = -1;
      break;
    }

    if (s[i] == '>') {
      if (st.top() != '<') {
        count++;
      }
      st.pop();
      continue;
    }

    if (s[i] == '}') {
      if (st.top() != '{') {
        count++;
      }
      st.pop();
      continue;
    }

    if (s[i] == ')') {
      if (st.top() != '(') {
        count++;
      }
      st.pop();
      continue;
    }

    if (s[i] == ']') {
      if (st.top() != '[') {
        count++;
      }
      st.pop();
      continue;
    }
  }

  if (count >= 0 && st.empty()) {
    cout << count;
  } else {
    cout << "Impossible";
  }

  return 0;
}