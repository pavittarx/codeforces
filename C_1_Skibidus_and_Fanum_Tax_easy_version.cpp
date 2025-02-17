// 2065A: Skibidus and Fanum tax (Easy)
// Problem: https://codeforces.com/contest/2065/problem/C1
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

    if (n == 1) {
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

    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;
      arr[i] = temp;
    }

    int value = 0;
    cin >> value;

    bool check = true;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (arr[i] > value - arr[i]) {
          arr[i] = value - arr[i];
        }
        continue;
      }

      int newVal = value - arr[i];
      if (newVal < arr[i] && newVal >= arr[i - 1]) {
        arr[i] = newVal;
        continue;
      }

      if (arr[i] >= arr[i - 1]) {
        continue;
      }

      if (value - arr[i] >= arr[i - 1]) {
        arr[i] = value - arr[i];
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