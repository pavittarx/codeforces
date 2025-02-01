// Mod.1 Compliation Errors
// Problem: https://codeforces.com/problemset/problem/519/B

#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;

  int i=0;
  int temp=0;
  
  while(i<3){
    int x;
    int sum=0;

    for(int j=0;j<n-i;j++){
      cin>>x;
      sum+=x;
    }

    if(i==0){
      temp = sum;
    }

    if(i > 0){
      int diff = temp - sum;
      cout<<diff<<endl;
      temp-=diff;
    }

    i++;
  }


}