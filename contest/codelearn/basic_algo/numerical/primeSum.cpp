#include <bits/stdc++.h>

using namespace std;

bool a[10000001];

void snt(int n)
{
  for (int i = 2; i <= n; i++)
  {
    a[i] = 1;
  }

  for (int i = 2; i <= sqrt(n); i++)
  {
    if (a[i])
    {
      for (int j = 2; j * i <= n; j++)
      {
        a[j * i] = 0;
      }
    }
  }
}

int primeSum(int n)
{
  int s = 0;
  snt(n);
  for (int i = 2; i <= n; i++)
  {
    if (a[i])
    {
      s += i % 22082018;
    }
  }
  return s;
}

int main()
{
  cout << primeSum(2);
}