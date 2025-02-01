#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  cin>>s;

  int size = s.length();

  string temp="";
  bool update = true;

  for(int i=0; i<size; i++){
    if(i == 0){
      temp+=towupper(s[i]);
      continue;
    }

    if(i>0 && islower(s[i])){
      update = false;
      break;
    }

    temp+=towlower(s[i]);
  }

  if(update && isupper(s[0])){
    temp[0]=towlower(temp[0]);
  }

  if(update){
    cout<<temp;
    return 0;
  }

  cout<<s;
}