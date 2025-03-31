// Contest Problem (2009 B)
// Problem: https://codeforces.com/contest/2009/problem/B

#include <iostream>
#include <stack>

using namespace std;

int main() {
  int cases;
  cin>>cases;

  while (cases != 0) {
    int rows;
    cin >> rows;

    stack<int> st;
    char ch;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < 4; j++) {
        cin>>ch;

        if(ch == '#'){
          st.push(j+1);
        }
      }
    }

    while(!st.empty()){
      cout<<st.top()<<" ";
      st.pop();
    }

    cout<<endl;

    cases--;
  }

  return 0;
}
