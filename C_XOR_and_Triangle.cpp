#include <iostream>
using namespace std;

bool degenTriangle(int x, int y) {
  int z = x ^ y;

  if (x + y > z && y + z > x && z + x > y) {
    return true;
  }

  return false;
}

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int x;
    cin >> x;

    int y = x / 2;

    for (; y >= 2; y--) {
      bool possible = degenTriangle(x, y);

      if (possible) {
        break;
      }
    }

    if (y >= 2) {
      cout << y << endl;
    } else {
      cout << "-1" << endl;
    }

    cases--;
  }

  return 0;
}