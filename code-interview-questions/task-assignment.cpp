#include <vector>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	vector<vector<int>> ans(k, vector<int>{});
	vector<pair<int,int>> tasksP;
	int i = 0;
	for(auto task: tasks) {
		tasksP.push_back({task, i++});
	}
	sort(tasksP.begin(),tasksP.end());
	int n = 2*k;
	for(int i=0;i<k;i++){
		ans[i].push_back(tasksP[i].second);
		ans[i].push_back(tasksP[n-i-1].second);
	}
  return ans;
}
