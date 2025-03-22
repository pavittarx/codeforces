// Contest (2009D) Satyam & Counting
// Problem: https://codeforces.com/contest/2009/problem/D

/*
  The expectation is to find, non-degenrate triangles from given points.
  If sides were given we could use,
  1. Triangle Inequality - to find non-degen triangles
  2. Pythagoras Theorem - to identify right angled triangle

  However, for cordinates we will use
  1. Points are non-colinear (not on the same line) - non degen triangle
  (x3-x2)(y2-y1) == (y3-y2)(x2-x1)
  2. Dot product equals zero for right angled triangle
  (x3-x2)(x2-x1) + (y3-y2)(y2-y1) == 0
*/

#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

bool checkDegenTraingle(Point& p1, Point& p2, Point& p3) {
  // (x3-x2)(y2-y1) == (y3-y2)(x2-x1)
  return (p3.x - p2.x) * (p2.y - p1.y) != (p3.y - p2.y) * (p2.x - p1.x);
}

bool checkRightTraingle(Point& p1, Point& p2, Point& p3) {
  // (x3-x2)(x2-x1) + (y3-y2)(y2-y1) == 0
  return ((p3.x - p2.x) * (p2.x - p1.x) + (p3.y - p2.y) * (p2.y - p1.y)) == 0;
}

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;

      Point p = {x, y};
      points.push_back(p);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          bool isDegen = checkDegenTraingle(points[i], points[j], points[k]);

          if (!isDegen) {
            continue;
          }

          bool isRightAngledTriangle =
              checkRightTraingle(points[i], points[j], points[k]) ||
              checkRightTraingle(points[j], points[k], points[i]) ||
              checkRightTraingle(points[k], points[i], points[j]);

          if (isDegen && isRightAngledTriangle) {
            count++;
          }
        }
      }
    }

    cout << count << endl;
    cases--;
  }

  return 0;
}