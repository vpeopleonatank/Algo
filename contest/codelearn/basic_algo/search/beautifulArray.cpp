bool beautifulArray(std::vector<int> arr)
{
	if(arr.size() == 1 || arr.size() == 2) return false;
	std::vector<int> v;
	for (int i = 0; i < arr.size(); ++i) {
		if(i == 0) v.push_back(arr[i]);
		else v.push_back(v[i-1]+arr[i]);
	}
	for(int i = 1; i < arr.size()-1; i++) {
		if(v[i-1] == v[arr.size()-1] - v[i]) return true;
	}
	return false;
}
