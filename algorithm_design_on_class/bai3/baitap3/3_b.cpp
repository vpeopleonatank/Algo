#include <iostream>

using namespace std;

int main() {
    freopen("so_b.in", "r", stdin);
    freopen("so_b.out", "w", stdout);

    int n, k = -1, x; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    int l = 0, r = n-1, m;
    while (l <= r) {
        m = (l+r) / 2;
        if (a[m] == x) {
            k = m;
            break;
        } else if (a[m] > x) {
            r = m-1;
        } else {
            l = m+1;
        }
    }

    cout << k;
}

