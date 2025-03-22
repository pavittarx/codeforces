// 545D (Queue)
// https://codeforces.com/problemset/problem/545/D

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  int timeSpent = 0;
  int count = 0;

  for (auto x : arr) {
    if (timeSpent <= x) {
      count++;
      timeSpent += x;
    }
  }

  cout << count << endl;

  return 0;
}