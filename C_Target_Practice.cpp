// Mod 2.2 Target Practive (1837C)
// Problem: https://codeforces.com/problemset/problem/1873/C
#include <iostream>
using namespace std;

int determineRingScore(int i, int j) {
  // 1st / Outermost Ring
  if (i == 0 || j == 0 || i==9 || j == 9) {
    return 1;
  }

  // 2nd Ring
  if (i == 1 || i==8 || j==1 || j==8) {
    return 2;
  }

  // 3rd Ring
  if(i==2 || i==7 || j==2 || j==7){
    return 3;
  }

  // 4th Ring
  if (i == 3 || i == 6 || j == 3 || j == 6) {
    return 4;
  }

  // 5th / Innermost Ring
  if (i == 4 || i == 5 || j == 4 || j == 5) {
    return 5;
  }
}

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int score = 0;
    int scorePoint = 0;
    for (int i = 0; i < 10; i++) {
      if (i < 5) {
        scorePoint++;
      }

      if (i >= 5) {
        scorePoint--;
      }

      for (int j = 0; j < 10; j++) {
        char c;
        cin >> c;

        if(c == 'X'){
          score+=determineRingScore(i, j);
        }
      }
    }

    cout << score << endl;
    cases--;
  }
}