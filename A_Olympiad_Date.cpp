// Contest [2091] Problem A (Olympiad Date)
// Link: https://codeforces.com/contest/2091/problem/A

#include <iostream>
#include <limits>
using namespace std;

bool checkPassed(int* req) {
  bool result =
      req[0] == 0 && req[1] == 0 && req[2] == 0 && req[3] == 0 && req[5] == 0;

  return result;
}

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int digits;
    cin >> digits;

    // cout << cases << " :cases digits" << digits << endl;

    int req[6];
    req[0] = 3;
    req[1] = 1;
    req[2] = 2;
    req[3] = 1;
    req[4] = 0;
    req[5] = 1;

    int i = 0;
    for (; i < digits; i++) {
      int d;
      cin >> d;

      if (d <= 5) {
        if (req[d] > 0) req[d]--;
        if (checkPassed(req)) {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
        }
      }
    }

    if (i <= digits && checkPassed(req)) {
      cout << i + 1 << endl;
    } else {
      cout << 0 << endl;
    }

    cases--;
  }

  return 0;
}