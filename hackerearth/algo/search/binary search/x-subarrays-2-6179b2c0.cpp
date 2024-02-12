#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n,x;
		cin>>n>>x;
		long long arr[n];
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		long long ans = 0;
		for (int i=0;i<n;i++) {
			int lo = i;
			int hi = n-1;
			int j = -1;
			while (lo <= hi) {
				int mid = lo + (hi-lo)/2;
				if (arr[i] + arr[mid] <= x) {
					lo = mid+1;
					j = mid;
				} else {
					hi = mid-1;
				}
			}

			if (j!=-1) {
				ans += (j-i+1);
			}
		}
		cout<<ans<<"\n";
    }
}