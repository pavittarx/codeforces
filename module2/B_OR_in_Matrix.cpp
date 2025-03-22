// [Mod.2 P8] OR in Matrix (486B)
// https://codeforces.com/problemset/problem/486/B

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int matrix[m][n];
  int matrixA[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
      matrixA[i][j] = 1;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) {
        int x = 0;
        while (x < n || x < m) {
          if (x < m) matrixA[x][j] = 0;
          if (x < n) matrixA[i][x] = 0;
          x++;
        }
      }
    }
  }

  bool same = true;
  int rows[m];
  int cols[n];
  fill_n(rows, m, -1);
  fill_n(cols, n, -1);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (rows[i] == -1) {
        rows[i] = 0;
        for (int k = 0; k < n; k++) {
          if (matrixA[i][k] == 1) {
            rows[i] = 1;
            break;
          }
        }
      }

      if (cols[j] == -1) {
        cols[j] = 0;
        for (int k = 0; k < m; k++) {
          if (matrixA[k][j] == 1) {
            cols[j] = 1;
            break;
          }
        }
      }

      int result = 0;
      if (rows[i] == 1 || cols[j] == 1) {
        result = 1;
      }

      if (result != matrix[i][j]) {
        same = false;
        break;
      }
    }

    if (!same) {
      break;
    }
  }

  if (same) {
    cout << "YES" << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrixA[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "NO" << endl;
  }

  return 0;
}