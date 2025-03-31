// 2065A: Skibidus and Ohio
// Problem: https://codeforces.com/contest/2065/problem/B
#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  cin.ignore();

  while (cases != 0) {
    string s = "";
    getline(cin, s);

    int count = 0;
    int size = s.length();
    for (int i = 0; i < size; i++) {
      if (i < size - 1 && s[i] == s[i + 1]) {
        count = 1;
        break;
      }

      count++;
    }

    cout << count << endl;

    cases--;
  }

  return 0;
}