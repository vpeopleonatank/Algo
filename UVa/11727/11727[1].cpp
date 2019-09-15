#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef LOCAL_DEFINE
        freopen("in.txt", "rt", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    int tc, a, b, c;
    cin >> tc;
    int i = 1;
    while(tc--) {
        cin >> a >> b >> c;
        int avg;
        if(a > b) {
            if(b > c) {
                avg = b;
            } else {
                if(a > c) {
                    avg = c;
                } else {
                    avg = a;
                }
            }
        } else {
            if(a > c) {
                avg = a;
            } else {
                if(b > c) {
                    avg = c;
                } else {
                    avg = b;
                }
            }
        }
        printf("Case %d: %d\n", i, avg);
        i++;
    }
    #ifdef LOCAL_DEFINE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    #endif
    return 0;
}