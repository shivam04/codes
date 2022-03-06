#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
	vector<vector<string>> ans;
	int n = words.size();
	unordered_map<string,vector<string>> mp;
  for(int i=0;i<n;i++) {
		string w = words[i];
		sort(w.begin(), w.end());
		mp[w].push_back(words[i]);
	}
	for(auto it=mp.begin(); it!=mp.end();it++) {
		ans.push_back(it->second);
	}
  return ans;
}
