#include <bits/stdc++.h>

using namespace std;

bool isHappy(int n)
{
  int step = 0;
  stack<int> s;
  while (step < 100000)
  {
    int sum = 0;
    while (n != 0)
    {
      int t = n % 10;
      sum += pow(t, 2);
      s.push(t);
      n /= 10;
    }
    if (sum == 1)
      return true;
    n = sum;
    // while (!s.empty())
    // {
    //   n = n * 10 + s.top();
    //   s.pop();
    // }
    step++;
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  if (isHappy(n))
    cout << "true";
  else
  {
    cout << "false";
  }
}