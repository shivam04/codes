vector<string> split(string a, char delim) {
	string temp = "";
	vector<string> ans;
	for(int i=0;i<a.length();i++) {
		if(a[i]==delim) {
			ans.push_back(temp);
			temp = "";
		} else {
			temp += a[i];
		}
	}
	return ans;
}