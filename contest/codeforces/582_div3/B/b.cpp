#include <iostream>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    int a[k];
    for (int i=0; i < k; i++) {
      cin >> a[i];
    }
    int bad = 0;
    for (int i = 0; i < k-1; i++) {
      for (int j = i+1; j < k; j++) {
       if (a[i] > a[j]) {
         bad++;
         break;
       }     
      }
    }
    cout << bad << endl;
  }
}

