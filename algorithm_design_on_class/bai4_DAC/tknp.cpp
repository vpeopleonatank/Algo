#include <iostream>

using namespace std;

int tknp(int a[100], int l, int r, int x) {
  int mid;
  if (l > r)
    return 0;
  mid = (l+r)/2;
  if (x == a[mid])
    return mid;
  else 
    if (x > a[mid])
      return tknp(a,mid+1,r,x);
    else
      return tknp(a,1,mid-1,x);
}

int main() {
  freopen("tknp.in", "r", stdin);
  freopen("tknp.out", "w", stdout);

  int n;
  cin >> n;
  while (n--) {
    int num, x;
    int a[num];
    cin >> x;
    cin >> num;
    for (int i = 0; i < num; i++) {
      cin >> a[i];
    }
    cout << tknp(a, 0, num-1, x) << endl;
  }
}
