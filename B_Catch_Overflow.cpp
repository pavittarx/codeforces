// Mod.2 P14 (1175B) Catch Overflow
// Problem: https://codeforces.com/problemset/problem/1175/B

#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

long long int LIMIT = 4294967295;

int main() {
  int commands;
  cin >> commands;

  stack<long long> st;
  stack<long long> sumStack;
  long long int x = 0;
  long long int lastLoopResult = 0;

  while (commands != 0) {
    string s;
    cin >> s;

    if (s[0] == 'a') {
      if (!st.empty()) {
        lastLoopResult += 1;
      } else {
        x++;
      }
    }

    if (s[0] == 'f') {
      int iterations;
      cin >> iterations;
      st.push(iterations);

      sumStack.push(lastLoopResult);
      lastLoopResult = 0;
    }

    if (s[0] == 'e') {
      if (!st.empty()) {
        int top = st.top();
        lastLoopResult = top * lastLoopResult;

        if (!sumStack.empty()) {
          lastLoopResult += sumStack.top();
          sumStack.pop();
        }

        st.pop();
      }

      if (st.empty()) {
        x += lastLoopResult;
        lastLoopResult = 0;
      }
    }

    if (lastLoopResult > LIMIT || x > LIMIT) {
      cout << "OVERFLOW!!!";
      return 0;
    }

    commands--;
  }

  if (x <= LIMIT) {
    cout << x;
  } else {
    cout << "OVERFLOW!!!";
  }

  return 0;
}