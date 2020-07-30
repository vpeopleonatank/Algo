#include <bits/stdc++.h>

using namespace std;

std::string truncateString(std::string s)
{
  while ((s[0] - '0') % 3 == 0 || ((s[s.size() - 1] - '0') % 3 == 0) || ((s[0] - '0') + (s[s.size() - 1] - '0')) % 3 == 0)
  {
    if ((s[0] - '0') % 3 == 0)
    {
      s.erase(0, 1);
    }
    else if ((s[s.size() - 1] - '0') % 3 == 0)
    {
      s.erase(s.size() - 1, 1);
    }
    else if (((s[0] - '0') + (s[s.size() - 1] - '0')) % 3 == 0)
    {
      s.erase(0, 1);
      s.erase(s.size() - 1, 1);
    }
    if(s.size() == 0) break;
  }
  return s;
}

int main()
{
  string s;
  cin >> s;
  cout << truncateString(s);
}