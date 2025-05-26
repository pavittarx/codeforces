#include <iostream>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases > 0) {
    long long n;
    cin >> n;

    long long sum = (n * (n + 1)) / 2;
    long long pow = 1;

    while (pow <= n) {
      sum -= pow * 2;
      pow *= 2;
    }

    cout << sum << endl;
    cases--;
  }

  return 0;
}