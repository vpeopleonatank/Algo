bool areSimilar(std::vector<int> a, std::vector<int> b)
{
	int d = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != b[i])
			d++;
	}
	if(d != 0 && d != 2)
		return false;

	if(d == 2) {
		int p = 0;
		for (int i = 0; i < a.size(); ++i) {
			if(a[i] != b[i]) {
				p = i;
				break;
			}
		}
		for(int i = p+1; i < a.size(); i++) {
			if(a[i] != b[i] && a[i] != b[p] && a[p] != b[i])
				return false;
		}
	}
	return true;
}
