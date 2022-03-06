using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
	int n = buildings.size();
	vector<int> ans;
  if(direction=="EAST") {
		for(int i=0;i<n;i++) {
			while(ans.size() > 0 and buildings[ans.back()] <= buildings[i])
				ans.pop_back();
			ans.push_back(i);
		}
	} else {
		for(int i=n-1;i>=0;i--) {
			while(ans.size() > 0 and buildings[ans.back()] <= buildings[i])
				ans.pop_back();
			ans.push_back(i);
		}
		reverse(ans.begin(), ans.end());
	}
  return ans;
}
