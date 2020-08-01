std::vector<int> missingValue(std::vector<int> a, std::vector<int> b)
{
	std::vector<bool> v(10000001);
	for(int i = 0; i < a.size(); i++) {
		v[a[i]] = true;
	}
	std::vector<int> c;
	for(int i = 0; i < b.size(); i++) {
		if(!v[b[i]])
			c.push_back(b[i]);
	}
	sort(c.begin(), c.end());
	return c;
}
