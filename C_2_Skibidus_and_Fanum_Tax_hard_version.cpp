// 2065A: Skibidus and Fanum tax (Hard)
// Problem: https://codeforces.com/contest/2065/problem/C2
#include <iostream>
#include <limits>
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

      cin.ignore(numeric_limits<streamsize>::max(), '\n');  // current line
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  // m line
      cin.ignore(numeric_limits<streamsize>::max(), '\n');  // n line

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
      int current_value = arr[i];

      int j = 0;
      while (j < m) {
        int temp = arr2[j] - arr[i];

        if (i == 0) {
          if (temp < current_value) {
            current_value = temp;
          }
          j++;
          continue;
        }

        if (temp >= arr[i - 1] && (current_value <= arr[i - 1])) {
          current_value = temp;
        }

        if (temp < current_value && temp >= arr[i - 1]) {
          current_value = temp;
        }

        j++;
      }

      arr[i] = current_value;
      if (i > 0 && arr[i] < arr[i - 1]) {
        check = false;
        break;
      }
    }

    cout << (check ? "YES" : "NO") << endl;
    cases--;
  }

  return 0;
}