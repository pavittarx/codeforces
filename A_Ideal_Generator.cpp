// Div.3 Contest A: Ideal Generator
// Problem: https://codeforces.com/contest/2093/problem/A

#include <iostream>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases > 0) {
    int n;
    cin >> n;

    if (n % 2 == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }

    cases--;
  }
}