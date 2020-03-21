#include<bits/stdc++.h>

using namespace std;



std::string formatString(std::string input)
{
  input = input.erase(0, input.find_first_not_of(" "));
  int l = input.length()-1;
  while(l > 0 && input[l] == ' ')
    l--;
}

int main()
{
  string s;
  cin >> s;
  cout << formatString(s);
}