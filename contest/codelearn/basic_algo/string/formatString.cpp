#include <bits/stdc++.h>

using namespace std;

std::string formatString(std::string input)
{
  int s = input.find_first_not_of(" ");
  int e = input.find_last_not_of(" ");
  input = input.substr(s, e - s + 1);
  int begin = input.find_first_of(" ");
  while (begin != string::npos)
  {
    int end = input.find_first_not_of(" ", begin);
    input = input.replace(begin, end - begin, " ");
    begin = input.find_first_of(" ", begin + 1);
  }
  return input;
}

int main()
{
  string s;
  getline(cin, s);
  cout << formatString(s);
}