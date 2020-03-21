#include <bits/stdc++.h>

using namespace std;

int partition(int a[100], int l, int r)
{
  int x = a[l];
  int i = l + 1, j = r;
  while (i < j)
  {
    while (i < j && a[i] < x)
    {
      i++;
    }
    while (j >= i && a[j] >= x)
    {
      j--;
    }
    if (i < j)
      swap(a[i], a[j]);
  }
  swap(a[l], a[j]);
  return j;
}

int partition1(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quick_sort(int a[100], int l, int r)
{
  if (l >= r)
    return;
  int i = partition1(a, l, r);
  quick_sort(a, l, i - 1);
  quick_sort(a, i + 1, r);
}

int main()
{
  freopen("quick_sort.in", "r", stdin);
  // freopen("quick_sort.out", "w", stdout);

  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
