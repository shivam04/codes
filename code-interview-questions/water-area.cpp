#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  int n = heights.size();
	if(n==0 || n==1)
		return 0;
	int leftM[n];
	int rightM[n];
	leftM[0] = heights[0];
	for(int i=1;i<n;i++) {
		leftM[i] = max(leftM[i-1], heights[i]);
	}
	rightM[n-1] = heights[n-1];
	for(int i=n-2;i>=0;i--) {
		rightM[i] = max(rightM[i+1], heights[i]);
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += (min(leftM[i], rightM[i]) - heights[i]);
	}
  return ans;
}
