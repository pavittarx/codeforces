// Mod2.13 (821C) Okabe and Boxes
// Problem: https://codeforces.com/problemset/problem/821/C

#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();

  int cases = 2 * n;
  int count = 0;

  stack<int> st;
  int expectedBox = 1;

  bool sorted = true;
  while (cases--) {
    string s;
    cin >> s;

    if (s[0] == 'a') {
      int boxNo;
      cin >> boxNo;

      st.push(boxNo);
    }

    if (s[0] == 'r') {

      // The boxes are expected to removed from 1->n.
      // if the expected box is at the top, it should be removed.
      if (!st.empty() && st.top() == expectedBox) {
        st.pop();
      } else {
        // If the expected box is not at top
        // and stack still has items, -> stack needs reordering.
        if (!st.empty()) {
          count++;

          // Once the stack is ordered, all the elements are sorted.
          // Hence, there is no need to track remaining elements.
          while (!st.empty()) st.pop();
        }
      }

      // There are 2n add commands, box 2 will be removed after box 1. 
      // We can track number of remove commands to track what item needs to be removed 
      expectedBox++;
    }
  }

  cout << count;

  return 0;
}
