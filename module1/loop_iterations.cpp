// Find out time taken 
// by for loop to complete 10^n iterations 
// where n goes from 1 to 12. 

#include<iostream>
#include<chrono>
#include<ctime>
#include<cmath>

using namespace std;

int main(){
  auto start = chrono::system_clock::now();

  long long last = pow(10, 12);
  int x = 1;
  long long next = pow(10, x);

  for(long long i = 1; i<=last; i++){
    if(i == next){
      auto now = chrono::system_clock::now();
      chrono::duration<double> elapsed_seconds = now - start;

      cout<<x<<"th iteration ("<<fixed<<elapsed_seconds.count()<<")"<<endl;
      x++;
      next = pow(10, x);
    }
  }

  auto end = chrono::system_clock::now();
  chrono::duration<double> elapsed_seconds = end - start;
  cout << "Last Iteration :" << std::fixed << elapsed_seconds.count() << ")" << endl;

  return 0;
}