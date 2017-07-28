#include <bits/stdc++.h>
using namespace std;
int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n,m;
	    cin>>n>>m;
	    long long a[n+1];
	    long long b[m+1];
	    long long i;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    for(i=0;i<m;i++)
	    cin>>b[i];
	    int j;
	    long long dp[m+1][n+1];
	    memset(dp,0,sizeof(dp));
	    for(i=1;i<=m;i++){
	        for(j=i;j<=n;j++){
	           dp[i][j] = max(dp[i-1][j-1]+a[j-1]*b[i-1],dp[i][j-1]);
	        }
	    }
	    cout<<dp[m][n]<<"\n";
	}
	return 0;
}