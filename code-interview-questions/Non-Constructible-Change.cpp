#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
	sort(coins.begin(), coins.end());
	int ans = 0;
	for(int c: coins) {
		if(c > ans+1) {
			return ans+1;
		}
		ans += c;
	}
  return ans+1;
}
