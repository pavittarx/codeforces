// Mod2 P6 (400B): Inna & New Matrix of Candies
// https://codeforces.com/problemset/problem/400/B

#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  set<int> steps;
  for (int i = 0; i < n; i++) {
    int score = 0;
    int startIndex = -1;
    bool broken = false;
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;

      if (ch == 'S') {
        // cout << "Hits: " << i << endl;
        if (startIndex != -1) {
          score = j - startIndex;
        }

        // All Dwarves need to get to the candy, if one cannot reach we cannot achieve the goal of the game.
        if (startIndex == -1) {
          cout << -1 << endl;
          return 0;
        }

        break;
      }

      if (ch == 'G') {
        startIndex = j;
      }
    }

    // ignore the rest...
    string s;
    getline(cin, s);

    if (score > 0) {
      steps.insert(score);
    }
  }

  int result = steps.size() > 0 ? steps.size() : -1;
  cout << result << endl;

  return 0;
}
