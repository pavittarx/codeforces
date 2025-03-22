// Mod 2. (1374C) Move Brackets
// Problem: https://codeforces.com/problemset/problem/1374/C

#include <iostream>
#include <stack>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int n;
    cin >> n;

    stack<char> st;
    int count = 0;

    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;

      if (st.empty() && ch == ')') {
        count++;
      }

      if (ch == ')' && !st.empty()) st.pop();

      if (ch == '(') {
        st.push('(');
      }
    }

    cout << count << endl;
    cases--;
  }
}