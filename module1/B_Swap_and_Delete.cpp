// CF Mod.1: Swap & Delete
// Challenge: https://codeforces.com/problemset/problem/1913/B

#include<iostream>
#include<cstdlib>

using namespace std;


int main(){
  int cases;
  cin>>cases;

  while(cases!=0){
    string s;
    cin>>s;

    if(s.length() < 1){
      cout<<s.length()<<endl;
      cases--;
      continue;
    }

    int zeroes = 0;
    int ones = 0;
    for(int i=0; i<s.length(); i++){
      if(s[i] == '0'){
        zeroes++;
      }

      if (s[i] == '1')
      {
        ones++;
      }


    }

    for(int i=0; i<s.length(); i++){
      if(s[i] == '0' && ones>0){
        ones--;
      }
      else if(s[i] == '1' && zeroes>0){
        zeroes--;
      }
      else{
        break;
      }
    }

    cout<<zeroes+ones<<endl;

    cases--;
  }
  
}