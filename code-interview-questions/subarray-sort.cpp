#include <vector>
using namespace std;
pair<int,int> smallerThanThat(vector<int> array, int p, int s, int n) {
	int mini = s;
	for(int i=s;i<n;i++) {
		if(array[i]<p) {
			p = array[i];
			mini = i;
		}
	}
	pair<int,int> ans = make_pair(p,mini);
	return ans;
}
vector<int> subarraySort(vector<int> array) {
  vector<int> ans{-1,-1};
	for(int i=1;i<array.size();i++) {
		if(array[i] < array[i-1]) {
			pair<int,int> aa = smallerThanThat(array, array[i], i, array.size());
			int p = aa.first;
			int j = aa.second-1;
			while(j>=0 and array[j]>p)
				j--;
			ans[0] = j==-1?0:j+1;
			break;
		}
	}
	for(int i=array.size()-2;i>=0;i--) {
		if(array[i] > array[i+1]) {
			int p = array[i];
			int j = i+1;
			while(j<array.size() and array[j]<p)
				j++;
			ans[1] = j-1;
			break;
		}
	}
  return ans;
}
