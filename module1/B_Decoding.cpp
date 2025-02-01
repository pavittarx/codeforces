#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  int n;
  cin >> n;

  string s;
  cin>>s;

  string temp="";

  for(int i=0; i<n; i++){
    if(n%2 != 0){
      temp = i%2 == 0 ? temp + s[i] : s[i] + temp;
      continue;
    }else{
      temp = i % 2 != 0 ? temp + s[i] : s[i] + temp;
    }
  }

  cout<<temp;

  return 0;
}