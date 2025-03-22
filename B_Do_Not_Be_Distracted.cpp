// PS16B: Do not be distracted
// Problem: https://codeforces.com/group/ItzpE9GqdX/contest/579655/problem/B

#include <iostream>
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
    bool isSuspicious = false;

    for (size_t i = 0; i < len; i++) {
      char ch;
      cin >> ch;

      if (i == 0) {
        current = ch;
        map[current] = true;
        continue;
      }

      if (ch != current) {
        current = ch;

        if (map[current]) {
          isSuspicious = true;
          break;
        }

        map[current] = true;
      }
    }

    cout << (isSuspicious ? "NO" : "YES") << endl;
    cases--;
  }

  return 0;
}