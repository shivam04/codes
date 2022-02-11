/*Time Complexity: O(n*n) 
Memory: O(n)
*/
#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  int n = array.size();
	int jumps[n+1];
	jumps[0] = 0;
	for(int i=1;i<n;i++) {
		jumps[i] = INT_MAX;
		for(int j=0;j<i;j++) {
			if(j+array[j]>=i and jumps[j] != INT_MAX) {
				jumps[i] = jumps[j] + 1;
				break;
			}
		}
	}
  return jumps[n-1];
}


/*Time Complexity: O(n) 
Memory: O(1)
*/

#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
	int n = array.size();
  int maxReach = array[0];
	int jumps = 1;
	int s = array[0];
	cout<<n<<"\n";
	for(int i=1;i<n;i++) {
		if(i==n-1)
			return jumps;
		maxReach = max(maxReach, i+array[i]);
		s--;
		cout<<"for "<<s<<" "<<maxReach<<"\n";
		if(s==0) {
			jumps++;
			s = maxReach-i;
			cout<<"if "<<s<<" "<<maxReach<<"\n";
		}
	}
  return 0;
}
