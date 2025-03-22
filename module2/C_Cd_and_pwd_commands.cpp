// Mod.2 Q10
// Problem: https://codeforces.com/problemset/problem/158/C

#include <iostream>
#include <vector>

using namespace std;

void printPath(vector<string> path) {
  for (auto x : path) {
    cout << "/" << x;
  }
  cout << "/" << endl;
}

vector<string> processCd(vector<string> path, string input) {
  if (input == "..") {
    path.pop_back();
  } else {
    path.push_back(input);
  }

  return path;
}

int main() {
  int n;
  cin >> n;

  vector<string> path;

  while (n >= 0) {
    string s;
    getline(cin, s);

    if (s == "pwd") {
      if (path.empty())
        cout << "/" << endl;
      else {
        printPath(path);
      }

      n--;
      continue;
    }

    // Process the `cd` command
    int i = 0;
    while (s[i] != ' ') {
      i++;
    }

    // Skip Space character
    i++;
    // Clear Path
    if (s[i] == '/') {
      vector<string> temp;
      path = temp;
      i++;
    }

    string dir = "";
    while (i < s.size()) {
      if (s[i] == '/') {
        if (dir.length()) {
          path = processCd(path, dir);
          dir = "";
        }
      } else {
        dir += s[i];
      }

      i++;
    }

    if (dir.length()) {
      path = processCd(path, dir);
    }

    n--;
  }

  return 0;
}