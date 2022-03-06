using namespace std;

string longestSubstringWithoutDuplication(string str) {
  unordered_map<char,int> mp;
	int start = 0;
	int i = 0;
	int n = str.size();
	int maxL = -1;
	int sI = 0;
	while(i<n) {
		if(mp.find(str[i]) != mp.end()) {
			start = max(start, mp[str[i]] + 1);
		}
		mp[str[i]] = i;
		if(maxL < i-start + 1) {
			maxL = i - start + 1;
			sI = start;
		}
		i++;
	}
  return str.substr(sI, maxL);;
}
