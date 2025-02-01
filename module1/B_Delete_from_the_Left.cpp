#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  string s, t;
  cin>>s>>t;

  int sSize = s.length();
  int tSize = t.length();

  int size = tSize > sSize ? tSize : sSize;

  if(s[sSize-1] != t[tSize -1]){
    cout<<sSize+tSize;
    return 0;
  }

  int i = 1;
  while(s[sSize-i] == t[tSize-i]){
    i++;
  }

  if(tSize-i == sSize-i && i>size){
    cout<<0;
    return 0;
  }

  cout<<sSize+tSize-(i-1)*2;
  return 0;
}