#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
	int i;
	int n = intervals.size();
	vector<vector<int>> ans;
	if(n==1 || n==0){
			return intervals;
	}
  sort(intervals.begin(), intervals.end());
	for(i=0;i<n;i++){
		int j = i;
		int m = intervals[i][1];
		while(j < n-1 and m>=intervals[j+1][0]){
				m = max(m, intervals[j+1][1]);
				j++;
		}
		if(j>i) {
			vector<int> temp;
			temp.push_back(intervals[i][0]);
			temp.push_back(max(m, intervals[j][1]));
			ans.push_back(temp);
		} else {
			ans.push_back(intervals[i]);
		}
		i=j;
	}
  return ans;
}
