#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  stack<int> s;
	int n = array.size();
	vector<int> ans(n, -1);
	for(int ii = 0; ii < 2*n; ii++) {
		int i = ii%n;
		while(!s.empty() and array[s.top()] < array[i]) {
			ans[s.top()] = array[i];
			s.pop();
		}
		s.push(i);
	}
  return ans;
}
