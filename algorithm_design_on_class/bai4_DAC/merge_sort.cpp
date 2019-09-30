#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int a[100], int l, int r) {
  if (l >= r)
    return;

  int t = l + (r - l) / 2;
  merge_sort(a, l, t);
  merge_sort(a, t + 1, r);
  merge(a, l, t, r);
}

int main() {
  freopen("in.merge_sort", "r", stdin);
  freopen("out.merge_sort", "w", stdout);

  int test_case;
  cin >> test_case;
  while (test_case--) {

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
