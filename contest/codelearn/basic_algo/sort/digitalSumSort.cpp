int sum(int a) {
	int s = 0;
	while(a) {
		s += a % 10;
		a /= 10;
	}
	return s;
}

std::vector<int> digitalSumSort(std::vector<int> a)
{
	for(int i = 0; i < a.size()-1; i++) {
		for(int j = i+1; j < a.size(); j++) {
			if(sum(a[i]) > sum(a[j]))
				swap(a[i], a[j]);
			if(sum(a[i]) == sum(a[j])) {
				if(a[i] > a[j])
					swap(a[i], a[j]);
			}
		}
	}

	return a;
}
