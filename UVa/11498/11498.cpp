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
    int tc, n, m, x, y;
    while (true)
    {
        cin >> tc; 
        if(tc == 0)
            break;
        cin >> n >> m;
        while(tc--) {
            cin >> x >> y;
            if(x == n || y ==m) {
                printf("divisa\n");
                continue;
            }
            if(x < n) {
                if(y > m) {
                    printf("NO\n");
                    continue;
                } else {
                    printf("SO\n");
                    continue;
                }
            } else {
                if(y > m) {
                    printf("NE\n");
                    continue;
                } else {
                    printf("SE\n");
                    continue;
                }
            }
        }
    }
    #ifdef LOCAL_DEFINE
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
    #endif
    return 0;
}