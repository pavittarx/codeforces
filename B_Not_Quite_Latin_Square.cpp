// Mod 2: (1915-B) Not Quite Latin Square
// Problem: https://codeforces.com/problemset/problem/1915/B
#include <iostream>

using namespace std;

int convertToInt(char c)
{
  if (c == 'A')
  {
    return 1;
  }

  if (c == 'B')
  {
    return 2;
  }

  if (c == 'C')
  {
    return 3;
  }

  return 0;
}

char convertToChar(int i){
  if (i == 1)
  {
    return 'A';
  }

  if (i == 2)
  {
    return 'B';
  }

  if (i == 3)
  {
    return 'C';
  }

  return 'n';
}

int main()
{
  int cases;
  cin >> cases;

  while (cases != 0)
  {
    int arr[3][3];
    int missingIndex[2];

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        char c;
        cin >> c;
        arr[i][j] = convertToInt(c);

        if(arr[i][j] == 0){
          missingIndex[0] = i;
          missingIndex[1] = j;
        }

      }
    }

    int result = 12;

    int i = missingIndex[0];
    int j = missingIndex[1];

    // Move Left
    int x = j;
    while(x >= 0){
      result-=arr[i][x];
      --x;
    }

    // Move Right
    x=j;
    while(x<3){
      result-=arr[i][x];
      ++x;
    }

    // Move Up
    x = i;
    while (x >= 0)
    {
      result -= arr[x][j];
      --x;
    }

    // Move Down
    x = i;
    while (x < 3)
    {
      result -= arr[x][j];
      ++x;
    }

    result/=2;
    cout<<convertToChar(result)<<endl;

    cases--;
  }


}