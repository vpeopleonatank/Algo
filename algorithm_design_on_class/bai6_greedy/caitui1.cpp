#include <bits/stdc++.h>

using namespace std;

void sortDesc(int a[], int b[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int v[m], w[m], wMax;
        cin >> wMax;
        for (int i = 0; i < m; i++) {
            cin >> v[i] >> w[i];
        }
        sortDesc(v, w, m);
        //for (int i = 0; i < m; i++) {
        //    cout << v[i] << " " << w[i] << endl;
        //}
        //break;
        int wSum = 0, valSum = 0;
        for (int i = 0; i < m; i++) {
            if (wMax >= wSum + w[i]) {
                wSum += w[i];
                valSum += v[i];
            } else
                break;
        }
        cout << valSum << endl;
    }

}
