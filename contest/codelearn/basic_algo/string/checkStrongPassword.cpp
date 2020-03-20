#include <bits/stdc++.h>

using namespace std;

bool check(string p, string dict)
{
  for (int j = 0; j < dict.length(); j++)
  {
    if (p.find(dict.at(j)) != string::npos)
    {
      return true;
    }
  }
  return false;
}

bool checkStrongPassword(std::string password)
{
  string nums = {"0123456789"};
  string chars = {"abcdefghijklmnpqrstuvwxyz"};
  string upper_chars = {"ABCDEFGHIJKLMNPQRSTUVWXYZ"};
  string spe_chars = "!@#$%^&*()-+";
  if (password.length() < 6)
    return false;
  if (check(password, nums))
  {
    if (check(password, chars))
    {
      if (check(password, upper_chars))
      {
        if (check(password, spe_chars))
        {
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  string s;
  cin >> s;
  if (checkStrongPassword(s))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}