// Mod.1 29 : Mahmoud & Triangle
// Problem: https://codeforces.com/problemset/problem/766/B

/*
  The problem says, the area of triangle must be positive, in other words, the triangle must be valid. 
  As only, valid triangle will have positive area.

  For a valid triangle (triangle inequality theorem)
  a+b > c
  b+c > a
  c+a > b

  Now, if we sort a, b, c then, a <= b <= c (c is always the largest).
  If we find that, (a+b > c). 
  c+a, c+b will always be > b, a.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int cases;
  cin>>cases;

  vector<int> arr;
  while(cases!=0){
    int temp;
    cin>>temp;
    arr.push_back(temp);

    cases--;
  }

  sort(arr.begin(), arr.end());

  for(int i=0; i<arr.size()-2; i++){
    if(arr[i] + arr[i+1] > arr[i+2]){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  
  cout<<"NO"<<endl;
  return 0;
}