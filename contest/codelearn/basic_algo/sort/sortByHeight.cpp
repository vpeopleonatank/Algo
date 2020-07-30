std::vector<int> sortByHeight(std::vector<int> a)
{
	std::vector<int> b = a;
	sort(a.begin(), a.end());
	int p;
	for (int i = 0; i < a.size(); ++i) {
		if(a[i] != -1) {
			p = i;
			break;
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		if(b[i] != -1) {
			b[i] = a[p];
			p++;
		}
	}
	return b;
}
