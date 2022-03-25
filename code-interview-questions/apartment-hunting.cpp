#include <vector>
#include <unordered_map>

using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
	int reqSz = reqs.size();
  vector<int> v[reqSz];
	int k = 0;
	for(string req: reqs) {
		vector<int> s;
		for(unordered_map<string, bool> block: blocks) {
			s.push_back(block[req]);
		}
		int n = s.size();
		vector<int> pre(n),suff(n);
		pre[0] = s[0]==1?0:1000000;
		for(int i=1;i<n;i++) {
			if(s[i]==1)
				pre[i] = 0;
			else
				pre[i] = pre[i-1]+1;
		}
		suff[n-1] = s[n-1]==1?0:1000000;
		for(int i=n-2;i>=0;i--) {
			if(s[i]==1)
				suff[i] = 0;
			else
				suff[i] = suff[i+1]+1;
		}
		for(int i=0;i<n;i++) {
			v[k].push_back(min(pre[i],suff[i]));
		}
		k++;
	}
	int ans = -1;
	int anss = 1000000;
	for(int i=0;i<blocks.size();i++) {
		int ps = 0;
		for(int j=0;j<reqSz;j++) {
			ps = max(ps, v[j][i]);
		}
		if(ps < anss) {
			anss = ps;
			ans = i;
		}
	}
  return ans;
}
