//O(n) O(n) memoization
#include <vector>
using namespace std;
map<int,int> mp;
int maxSubsetSumNoAdjacentUtil(vector<int> array, int n) {
	if(n<0)
		return 0;
	if(n==0)
		return array[n];
	if(n==1)
		return max(array[0], array[1]);
	if(mp.find(n) != mp.end())
		return mp[n];
	return mp[n]=max(maxSubsetSumNoAdjacentUtil(array,n-1), array[n]+maxSubsetSumNoAdjacentUtil(array, n-2));
}
int maxSubsetSumNoAdjacent(vector<int> array) {
	mp.clear();
  return maxSubsetSumNoAdjacentUtil(array, array.size()-1);
}



//O(N) O(N) iteration

#include <vector>
using namespace std;
int maxSubsetSumNoAdjacent(vector<int> array) {
	int n = array.size();
	if(n==0)
		return 0;
	if(n==1)
		return array[n-1];
	if(n==2)
		return max(array[n-1], array[n-2]);
	vector<int> dp = array;
	dp[1] = max(array[0], array[1]);
	for(int i=2;i<n;i++) {
		dp[i] = max(dp[i-1], dp[i-2]+array[i]);
	}
	return dp[n-1];
}


//O(n) O(1) in memory update
#include <vector>
using namespace std;
int maxSubsetSumNoAdjacent(vector<int> array) {
	int n = array.size();
	if(n==0)
		return 0;
	if(n==1)
		return array[n-1];
	if(n==2)
		return max(array[n-1], array[n-2]);
	array[1] = max(array[0], array[1]);
	for(int i=2;i<n;i++) {
		array[i] = max(array[i-1], array[i-2]+array[i]);
	}
	return array[n-1];
}


//O(n) O(1) without update
#include <vector>
using namespace std;
int maxSubsetSumNoAdjacent(vector<int> array) {
	int n = array.size();
	if(n==0)
		return 0;
	if(n==1)
		return array[n-1];
	if(n==2)
		return max(array[n-1], array[n-2]);
	int cm = max(array[0], array[1]);
	int pm = array[0];
	for(int i=2;i<n;i++) {
		int c = max(cm, pm+array[i]);
		pm = cm;
		cm = c;
	}
	return cm;
}
