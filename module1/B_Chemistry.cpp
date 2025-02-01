#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  int cases;
  cin >> cases;

  // cout << cases;

  while(cases !=0){
      int n, k;
      cin>>n>>k;

      string s;
      cin >> s;

      if(n<k || n-k == 0){
          cout<<"NO"<<endl;
          cases--;
          continue;
      }

      if(n-k == 1){
          cout<<"YES"<<endl;
          cases--;
          continue;
      }

      map<char, int> m;
      int diff = n - k;

      for(int i=0; i<n; i++){
          m[s[i]]++;
      }

      int clean = 0; 
      int bad = 0;

      for(auto it: m){
        int count = it.second;

        if(count%2 == 0){
          clean+=count;
        }
        
        if(count%2 != 0){
          bad+=1;
          clean += count - 1;
        }
      }

      if(clean >= diff-1){
        cout<<"YES"<<endl;
      }else{
        cout<<"NO"<<endl;
      }

      cases--;
  }

  return 0;
}