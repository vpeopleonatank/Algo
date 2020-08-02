#include <bits/stdc++.h>

using namespace std;

void f(int i, int n, int a[]) {
  if(n == i) return;
  f(i+1,n,a);
  cout << a[i];
}

int main() {
  int a[5] = {5,4,3,2,1};
  f(0, 5, a);
}
