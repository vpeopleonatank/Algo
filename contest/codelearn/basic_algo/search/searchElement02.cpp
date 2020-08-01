int searchElement02(std::vector<std::vector<int>> a, int k)
{
	std::vector<int> v;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[0].size(); ++j) {
			v.push_back(a[i][j]);
		}
	}
	sort(v.begin(), v.end());
	int c = 1;
	if(k == 1) return v[0];
		for (int i = 1; i < v.size(); ++i) {
			if(v[i] != v[i-1]) {
				c++;
			}
			if(c == k) return v[i];
		}
	return -1;
}
