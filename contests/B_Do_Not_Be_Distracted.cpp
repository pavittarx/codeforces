// PS16B: Do not be distracted
// Problem: https://codeforces.com/group/ItzpE9GqdX/contest/579655/problem/B

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int len;
    cin >> len;
    unordered_map<char, bool> map;

    char current;
    bool canBeSuspicious = false;

    for (size_t i = 0; i < len; i++) {
      char ch;
      cin >> ch;

      if (i == 0) {
        current = ch;
        continue;
      }

      if (ch != current) {
        map[current] = 1;

        if (map[ch] == 1) {
          canBeSuspicious = true;
          string s;
          getline(cin, s);
          break;
        }

        current = ch;
      }

      if (i == len - 1) {
        if (map[ch] == 1) {
          canBeSuspicious = true;
        }
      }
    }

    cout << (canBeSuspicious ? "NO" : "YES") << endl;
    cases--;
  }

  return 0;
}