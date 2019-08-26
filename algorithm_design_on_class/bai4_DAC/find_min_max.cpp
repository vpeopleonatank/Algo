#include <iostream>

using namespace std;

void MinMax(int a[100], int l, int r, int &min, int &max) {
  int min1, min2, max1, max2;
  cout << "+1\n";
  if (l == r) {
    min = a[l];
    max = a[l];
  } else {
    MinMax(a, l, (l+r)/2, min1, max1);
    MinMax(a, (l+r)/2+1, r,min2, max2);
    
    if (min1 < min2)
      min = min1;
    else
      min = min2;
    if (max1 > max2)
      max = max1;
    else
      max = max2;
  }
}

int main() {
  freopen("find_min_max.in", "r", stdin);
  freopen("find_min_max.out", "w", stdout);

  int n, min, max;
  int a[n];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  MinMax(a, 0, n-1, min, max);
  cout << "min: " << min << " max: " << max;

}
