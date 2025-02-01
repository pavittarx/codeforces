#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  map<string, string> m;

  while(k!=0){
    string lang1, lang2;

    cin>>lang1>>lang2;

    if(lang1.length() > lang2.length()){
      m[lang1] = lang2; 
    }else{
      m[lang1] = lang1;
    }

    k--;
  }

  while(n!=0){
    string s;
    cin>>s;

    cout<<m[s]<<" ";
    n--;
  }

  
  return 0;
}