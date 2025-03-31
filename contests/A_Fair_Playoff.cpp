// Contest: PS16 579655A
// Problem: https://codeforces.com/group/ItzpE9GqdX/contest/579655/problem/A

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int max = 0;
    int nextMax = 0;
    vector<int> skills;

    int n = 4;
    for (int i = 0; i < n; i++) {
      int temp;
      cin >> temp;

      if (i == 0) {
        max = temp;
      }

      if (i == 1) {
        nextMax = temp;
      }

      if (i > 0 && temp > max) {
        nextMax = max;
        max = temp;
      }

      if (temp < max && temp > nextMax) {
        nextMax = temp;
      }

      skills.push_back(temp);
    }

    int finalTeam1 = skills[0] > skills[1] ? skills[0] : skills[1];
    int finalTeam2 = skills[2] > skills[3] ? skills[2] : skills[3];

    if ((finalTeam1 == max || finalTeam1 == nextMax) &&
        (finalTeam2 == max || finalTeam2 == nextMax)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }

    cases--;
  }

  return 0;
}