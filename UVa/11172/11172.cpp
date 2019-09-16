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
	int tc;
	cin >> tc;
	while(tc--) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			printf(">");
		} else if (a < b) {
			printf("<");
		} else 
			printf("=");
		printf("\n");
	}
	#ifdef LOCAL_DEFINE
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
	#endif
	return 0;
}
