#include <iostream>

using namespace std;

int partition(int a[100], int l, int r) {
  int x = a[l];
  int i = l+1, j = r;
  while (i < j) {
    while (i < j && a[i] < x) {
      i++;
    }
    while (j >= i && a[j] >= x) {
      j--;
    }
    if (i < j)
      swap(a[i], a[j]);
  }
  swap(a[l], a[j]);
  return j;
}

void quick_sort(int a[100], int l, int r) {
  if (l >= r)
    return;
  int i = partition(a, l, r);
  quick_sort(a,l, i-1);
  quick_sort(a, i+1, r);
}

int main() {
  freopen("quick_sort.in", "r", stdin);
  freopen("quick_sort.out", "w", stdout);  

  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  quick_sort(a, 0, n-1);
  
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

