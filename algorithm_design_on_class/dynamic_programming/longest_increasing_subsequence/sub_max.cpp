#include <bits/stdc++.h>

using namespace std;

int i, j;

void SubMax(int arr[], int n) {
  int MaxS = arr[0], MaxE = arr[0];
  // s: chi so dau, e: chi so cuoi, s1: chi so dau tam
  int s = 1, e = 1, s1 = 1;
  for(i = 1; i < n; i++) {
    if(MaxE > 0) {
      MaxE = MaxE + arr[i];
    } else {
      MaxE = arr[i];
      s1 = i;
    }

    if(MaxE > MaxS) {
      MaxS = MaxE;
      e = i;
      s = s1;
    }
  }

  for(i = s; i <= e; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Tong con lon nhat lien tiep " << MaxS << endl;
}

int main() {
  freopen("in.sub_max", "r", stdin);
  freopen("out.sub_max", "w", stdout);  

  int test_case;
  cin >> test_case;
  while(test_case--) {
    int n;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++) {
      cin >> arr[i];
    }
    SubMax(arr,n);
  }
}

