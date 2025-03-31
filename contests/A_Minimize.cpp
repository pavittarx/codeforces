// Contest Problem (2009/A)
// Problem: https://codeforces.com/contest/2009/problem/A

// Given a, b
// we need to find value that satisifies (c-a) + (b-c)
// i.e. c-a+b-c => -a + b => b-a

#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;

  while (cases != 0) {
    int a, b;
    cin>>a>>b;

    cout<<b-a<<endl;

    cases--;
  }

  return 0;
}