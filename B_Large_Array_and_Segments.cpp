// Educational Codeforces Round (2086-B)
// large Array & Segments
// Problem: https://codeforces.com/contest/2086/problem/B

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    long long n, k, x;
    cin >> n >> k >> x;

    vector<int> nums(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nums.push_back(x);
      sum += x;
    }

    cout << "sum: " << sum * k << endl;

    long long result = (sum * k) / x;

    cout << result * k << endl;

    cases--;
  }

  return 0;
}