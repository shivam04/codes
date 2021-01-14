#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    int arr[n][m];
	    int ans = -1;
	    int anss = INT_MAX;
	    int sum = 0;
	    for(int i=0;i<n;i++) {
	        sum = 0;
	        for(int j=0;j<m;j++) {
	            cin>>arr[i][j];
	            sum+=arr[i][j];
	        }
	        if(sum>0 and sum<anss) {
	            anss = sum;
	            ans = i;
	        }
	    }
	    cout<<ans<<"\n";
	    
	}
	return 0;
}