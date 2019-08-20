#include <iostream>

using namespace std;

int main() {
    freopen("3_a.in", "r", stdin):
    freopen("3_a.out", "w", stdout);

    int n, k = -1, x; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            k = i;
        }
    }
    cout << k;
}
