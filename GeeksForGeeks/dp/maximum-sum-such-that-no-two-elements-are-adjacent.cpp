#include <bits/stdc++.h>
using namespace std;
int ans(int a[],int n,int m){
    //cout<<n<<" "<<m<<"\n";
    if(m>=n)
    return 0;
    return max(a[m]+ans(a,n,m+2),ans(a,n,m+1));
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    //cout<<t<<"\n";
	    int n;
	    cin>>n;
	    int i;
	    int x[1001];
	    for(i=0;i<n;i++){
	        cin>>x[i];
	    }
	    //cout<<n<<"\n";
	    //cout<<ans(x,n,0)<<"\n";
	    int ans;
	    int dp[2][n+1];
	    dp[0][0] = x[0];
	    dp[1][0] = 0;
	    for(i=1;i<n;i++){
	        dp[1][i] = max(dp[0][i-1],dp[1][i-1]);
	        dp[0][i] = dp[1][i-1] + x[i];
	    }
	    cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";
	}
	return 0;
}