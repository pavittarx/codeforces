// 2065A: Skibidus and Fanum tax (Easy)
// Problem: https://codeforces.com/contest/2065/problem/C2
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  cin.ignore();

  while (cases != 0) {
    int n, m;
    cin >> n >> m;

    if (n <= 1) {
      cout << "YES" << endl;

      // Ignore this testcase
      string s;
      cin.ignore();
      getline(cin, s);
      getline(cin, s);

      cases--;
      continue;
    }

    vector<int> arr(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      arr[i] = temp;
    }

    for (int i = 0; i < m; i++) {
      int temp;
      cin >> temp;
      arr2[i] = temp;
    }

    bool check = true;
    for (int i = 0; i < n; i++) {
      int min = arr[i];

      if (i == 0) {
        int j = 0;
        while (j < m) {
          int temp = arr2[j] - arr[i];

          if (temp < min) {
            min = temp;
          }

          j++;
        }

        arr[i] = min;
        continue;
      }

      int j = 0;
      while (j < m) {
        int temp = arr2[j] - arr[i];

        if (temp <= min && temp >= arr[i - 1]) {
          min = temp;
        }

        j++;
      }

      arr[i] = min;

      if (arr[i] >= arr[i - 1]) {
        continue;
      }

      check = false;
      break;
    }

    cout << (check ? "YES" : "NO") << endl;

    cases--;
  }

  return 0;
}