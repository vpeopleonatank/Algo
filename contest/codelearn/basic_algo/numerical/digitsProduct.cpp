#include <bits/stdc++.h>

using namespace std;

int digitsProduct(int product)
{
  if (product == 0)
    return 10;
  if (product == 1)
    return 1;
  int c(0), t(0);
  for (int i = 9; i > 1; i--)
  {
    while (product % i == 0)
    {
      product /= i;
      c = i * pow(10, t) + c;
      t++;
    }
  }
  return c ? c : -1;
}

int main()
{
  cout << digitsProduct(12);
}