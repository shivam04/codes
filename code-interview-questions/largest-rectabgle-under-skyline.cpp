#include <vector>
#include <stack>
using namespace std;

int largestRectangleUnderSkyline(vector<int> buildings) {
  int ans = 0;
	stack<int> s;
	int n = buildings.size();
	for(int i=0;i<n;) {
		if(s.empty() or buildings[s.top()] <= buildings[i]) {
			s.push(i++);
			continue;
		}
		int tp = s.top();
		s.pop();
		int area = buildings[tp]*(s.empty() ? i : i-s.top()-1);
		ans = max(ans, area);
	}
	
	while(!s.empty()) {
		int tp = s.top();
		s.pop();
		int area = buildings[tp]*(s.empty() ? n : n-s.top()-1);
		ans = max(ans, area);
	}
  return ans;
}
