#include <bits/stdc++.h>

using namespace std;

void MinMax(int a[100], int l, int r, int &min, int &max) {
  int min1, min2, max1, max2;
  // cout << "+1\n";
  if (l == r) {
    min = a[l];
    max = a[l];
  } else {
    MinMax(a, l, (l + r) / 2, min1, max1);
    MinMax(a, (l + r) / 2 + 1, r, min2, max2);

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
  freopen("in.find_min_max", "r", stdin);
  // freopen("out.find_min_max", "w", stdout);

  int test_case;
  cin >> test_case;

  while (test_case--) {
    int n, min, max;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    MinMax(a, 0, n - 1, min, max);
    cout << "min: " << min << " max: " << max << endl;
  }
}
