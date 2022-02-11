#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
	set<int> st;
	int mini = *min_element(array.begin(), array.end());
	int maxi = *max_element(array.begin(), array.end());
	int n = array.size();
	for(int i=0;i<n;i++) {
		st.insert(array[i]);
	}
	array.clear();
	for(int n: st) {
		array.push_back(n);
	}
	vector<int> ans{-1,-1};
	n = array.size();
	int maxL = -1;
	if(n==1) {
		ans[0] = array[0];
		ans[1] = array[0];
		return ans;
	}
	for(int i=1;i<n;i++) {
		int j = i;
		int l = 1;
		while(j < n and array[j] - array[j-1] == 1) {
			j++;
			l++;
		}
		if(l > maxL) {
			maxL = l;
			ans[0] = array[i-1];
			ans[1] = array[j-1];
		}
		i=j;
	}
	return ans;
}
