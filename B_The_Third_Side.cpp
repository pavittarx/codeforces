// Contest 2074B Div.3
// Problem: https://codeforces.com/contest/2074/problem/B

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

bool comp(int a, int b) { return a > b; }

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int n;
    cin >> n;

    if (n == 1) {
      int temp;
      cin >> temp;
      cout << temp << endl;
      cases--;
      continue;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), comp);

    int result = nums[0];

    for (int i = 1; i < n; i++) {
      result += nums[i] - 1;
    }

    cout << result << endl;

    cases--;
  }

  return 0;
}