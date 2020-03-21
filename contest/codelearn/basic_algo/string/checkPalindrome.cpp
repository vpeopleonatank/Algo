#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(std::string inputString)
{
  if(inputString.length() == 1) return true;
  for(int i = 0; i < inputString.length(); i++)
  {
    if(i > inputString.length()-i-1)
      break;
    if(inputString[i] != inputString[inputString.length()-i-1])
      return false;
  }
  return true;
}

int main()
{
  string s;
  cin >> s;
  if(checkPalindrome(s))
    cout << "true";
  else
  {
    cout << "false";
  }
  
}