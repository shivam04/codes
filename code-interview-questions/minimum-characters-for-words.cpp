#include <vector>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
	unordered_map<char, int> mp, mpf;
	for(auto word: words) {
		mp.clear();
		for(auto c: word) {
			mp[c] += 1;
		}
		for(auto [c, f]: mp) {
			mpf[c] = max(mpf[c], f);
		}
	}
	vector<char> ans;
	for(auto [c, f]: mpf) {
		for(int i=0;i<f;i++) {
			ans.push_back(c);
		}
	}
  return ans;
}