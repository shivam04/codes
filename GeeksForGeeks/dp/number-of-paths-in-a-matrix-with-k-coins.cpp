#include<bits/stdc++.h>
using namespace std;
long arr[201][201];
long dp[201][201][201];
long ans(int n, int m, int k) {
    if (m < 0 || n < 0) return 0;
    if(n==0 and m==0) {
        return (k==arr[n][m]);
    }
    if(dp[n][m][k] != -1)
        return dp[n][m][k];
    return dp[n][m][k]=ans(n-1, m, k-arr[n][m]) + ans(n, m-1, k-arr[n][m]); 
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    memset(dp,-1,sizeof(dp));
	    long n,k;
	    cin>>k>>n;
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<n;j++) {
	            cin>>arr[i][j];
	        }
	    }
	    cout<<ans(n-1,n-1,k)<<"\n";
	}
	return 0;
}