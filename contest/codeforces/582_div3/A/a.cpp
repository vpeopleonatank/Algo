#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int n;
  cin >> n;
  int k, odd = 0;
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (k%2 != 0) {
      odd++;
    }
  }

  if (odd < n-odd)
    cout << odd;
  else
    cout << n-odd;
  
}

