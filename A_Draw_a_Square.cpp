// Draw a Square [2074A]
// Problem: https://codeforces.com/contest/2074/A

#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  cin.ignore();

  while (cases != 0) {
    int l, r, d, u;

    cin >> l >> r >> d >> u;

    if (l == r && r == d && d == u) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

    cases--;
  }

  return 0;
}