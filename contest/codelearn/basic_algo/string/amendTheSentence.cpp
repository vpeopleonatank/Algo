#include <bits/stdc++.h>

using namespace std;
//CodesignalIsAwesome
std::string amendTheSentence(std::string s)
{
  string out = "";
  int i = 0;
  while (s.length() > i)
  {
    out += tolower(s[i]);
    i++;
    int pre = i;
    while (i < s.length() && s[i] != toupper(s[i]))
    {
      i++;
    }
    out += s.substr(pre, i - pre);
    if(i < s.length())
      out += " ";
  }
  return out;
}

int main()
{
  string s;
  cin >> s;
  cout << amendTheSentence(s);
}