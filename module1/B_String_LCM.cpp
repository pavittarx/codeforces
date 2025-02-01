// CF: Mod.1 String LCM
// https://codeforces.com/problemset/problem/1473/B

#include <iostream>
#include <map>
#include <vector>

using namespace std;

string findGCD(string s1, string s2){
  if(s1.length() < s2.length()){
    return findGCD(s2, s1);
  }

  int s1Size = s1.length();
  int s2Size = s2.length();

  // If two strings does not have same starting character
  if(s1[0] != s2[0]){
    return "";
  }

  if(s1+s2 != s2+s1){
    return "";
  }

  // Apply Euclid's GCD Algorithm
  string r = "";
  while(true){
    int i =0;
    while(i<s2.length()){
      if(s1[i] != s2[i]){
        return "";
      }

      i++;
    }

    if(s1.length() > i-1){
      r = s1.substr(i);
      s1 = r;
    }

    return s2;
  }


  return s2;
}

string findLCM(string gcd, string s1, string s2){
  string lcm = gcd;

  while (lcm.length() % s1.length() != 0 || lcm.length() % s2.length() != 0){
      lcm+=gcd;
  }

  int size = lcm.length();
  int s1Size = s1.length();
  int s2Size = s2.length();

  // Perform Check if lcm is correct
  for(int i=0; i<size; i++){
    if(lcm[i] != s1[i%s1Size]){
      return "";
    }

    if (lcm[i] != s2[i%s2Size]){
      return "";
    }
  }

  return lcm;
}

int main()
{
  int cases;
  cin >> cases;

  while (cases != 0)
  {
    string s, x;
    cin >> s >> x;

    int sSize = s.length(), xSize = x.length();

    if (sSize == xSize)
    {
      
      if (s == x){
        cout << s << endl;
      }
      else{
        cout << -1 << endl;
      }

      cases--;
      continue;
    }

    string gcd = findGCD(s, x);
    // No Common divisor, so LCM is not possible

    if(gcd == ""){
      cout<<-1<<endl;
      cases--;
      continue;
    }

    string lcm = findLCM(gcd, s, x);

    if(lcm == ""){
      cout<<-1<<endl;
    }else{
      cout<<lcm<<endl;
    }

    cases--;
  }

  return 0;
}