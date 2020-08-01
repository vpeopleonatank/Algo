int countPlace(std::vector<int> a, int k)
{
	int cur = 0, i, c = 0;
	while(cur < a.size()) {
		if(cur == a.size() - 1)
			return ++c;
		i = cur+1;
		while(a[i] - a[cur] <= k) {
			i++;
		}
		i = i -1;
		if(cur != i) {
			int p = i+1;
			while(a[p] - a[i] <= k) {
				p++;
			}
			cur = p;
			c++;
		} else {
			cur++; c++;
		}
	}
	return c;
}
