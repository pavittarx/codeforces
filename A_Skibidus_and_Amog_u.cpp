// 2065A: Skibidus and Amog'u
// Problem: https://codeforces.com/contest/2065/problem/A
#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  cin.ignore();

  while (cases != 0) {
    string s = "";
    getline(cin, s);

    string plural = "";
    for (int i = 0; i < s.length() - 2; i++) {
      plural = plural + s[i];
    }

    plural = plural + 'i';
    cout << plural << endl;

    cases--;
  }

  return 0;
}