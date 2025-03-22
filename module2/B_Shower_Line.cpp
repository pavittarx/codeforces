// Mod.2 P7: Shower Line
// Problem: https://codeforces.com/problemset/problem/431/B
#include <iostream>
using namespace std;

int main() {
  int n = 5;
  int scores[5][5];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int num;
      cin >> num;
      scores[i][j] = num;
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }

      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }

        for (int l = 0; l < n; l++) {
          if (l == i || l == j || l == k) {
            continue;
          }

          for (int m = 0; m < n; m++) {
            if (m == i || m == j || m == k || m == l) {
              continue;
            }

            int resultT = scores[i][j] + scores[k][l] + scores[j][k] +
                          scores[l][m] + scores[k][l] + scores[l][m];

            resultT += scores[j][i] + scores[l][k] + scores[k][j] +
                       scores[m][l] + scores[l][k] + scores[m][l];

            if (resultT > result) {
              result = resultT;
            }
          }
        }
      }
    }
  }

  cout << result;

  return 0;
}