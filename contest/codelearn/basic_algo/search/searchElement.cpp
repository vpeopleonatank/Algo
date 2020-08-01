bool comparator(int &a, int &b) {
	return a > b;
}

int searchElement(std::vector<int> a, int n)
{
	if(n == 0) return -1;
	sort(a.begin(), a.end(), comparator);
	if(n == 1) return a[0];
	int c = 1;
	for (int i = 1; i < a.size(); ++i) {
		if(a[i] < a[i-1])
			c++;
		if(c == n) return a[i];
	}
	return -1;
}
