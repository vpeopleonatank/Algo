#include <iostream>

using namespace std;

int main() {
    int n, b, testNum;
    freopen("so.in", "r", stdin);
    freopen("so.out", "w", stdout);
    cin >> testNum;
    while (testNum--) {
        cin >> n;
        int a[n+1], c[n+1];
        for (int i = n; i >= 1; i--) {
            cin >> a[i];
        }

        cin >> b;
        int rem = 0, tg;
        for (int i = 1; i <= n; i++) {
            tg = b * a[i] + rem;
            c[i] = tg % 10;
            rem = tg / 10;
        }
        if (rem > 0) {
            n++;
            c[n] = rem;
        }
        for (int i = n; i >= 1; i--) {
            cout << c[i];
        }
        cout << endl;
    }


}
