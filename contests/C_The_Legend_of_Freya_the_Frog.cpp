// Contest Problem (2009 C)
// Problem: https://codeforces.com/contest/2009/problem/C

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    double x, y, d;
    cin >> x >> y >> d;

    int xSteps = ceil(x / d);
    int ySteps = ceil(y / d);

    if (xSteps > ySteps) {
      cout << 2 * xSteps - 1 << endl;
    } else {
      cout << 2 * ySteps << endl;
    }

    cases--;
  }

  return 0;
}