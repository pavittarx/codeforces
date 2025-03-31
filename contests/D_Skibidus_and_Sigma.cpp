// Skibidus & Sigma (2065D)
// Problem: https://codeforces.com/contest/2065/problem/D

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

auto comp = [](pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
};

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> scores(n);
    for (int i = 0; i < n; i++) {
      long long sum = 0;
      long long score = 0;
      for (int j = 0; j < m; j++) {
        long long temp;
        cin >> temp;
        sum += temp;
        score += (m - j) * temp;
      }

      pair<long long, long long> p = {score, sum};
      scores[i] = p;
    }

    long long totalScore = 0;
    sort(scores.begin(), scores.end(), comp);

    for (int i = 0; i < scores.size(); i++) {
      if (i == 0) {
        totalScore = scores[i].first;
        continue;
      }

      if (i > 0) {
        long long sum = 0;
        int n = i-1;
        while(n>=0){
          sum+=scores[i].second;
          n--;
        }

        totalScore += m*sum + scores[i].first;
      }
    }

    cout << totalScore << endl;

    cases--;
  }

  return 0;
}