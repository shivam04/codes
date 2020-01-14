#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    long long arr[n];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    long long left[n], right[n];
	    left[0] = arr[0];
	    for(int i=1;i<n;i++) {
	        left[i] = max(left[i-1], arr[i]);
	    }
	    right[n-1] = arr[n-1];
	    for(int i=n-2;i>=0;i--) {
	        right[i] = max(right[i-1], arr[i]);
	    }
	    long long ans = 0;
	    for(int i=0;i<n;i++) {
	        ans = ans + min(left[i], right[i]) - arr[i];
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}