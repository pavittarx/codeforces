// Mod 2 (1850C) 3. Word on the Paper
// Problem: https://codeforces.com/problemset/problem/1850/C

#include<iostream>

using namespace std;

int main(){
  int cases;
  cin>>cases;

  int n = 8;
  while(cases!=0){
    string s;
    char ch;

    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin>>ch;

        if(ch >= 'a'){
          s = s+ch;
        }
      }
    }

    cout<<s<<endl;
    cases--;
  }
}