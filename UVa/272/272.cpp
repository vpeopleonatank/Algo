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
	char str[10000];
	bool begin = true;
	while(gets(str)) {
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (str[i] == '"') {
				if (begin) {
					printf("``");
					begin = false;
				} else {
					printf("''");
					begin = true;
				}
			} else
				printf("%c", str[i]);
		}
		printf("\n");
	}
	#ifdef LOCAL_DEFINE
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s. \n";
	#endif
	return 0;
}
