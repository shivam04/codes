#include<bits/stdc++.h>
using namespace std;
int dp[41+1][41+1];
int ans(string a,int l,int h){
    if(dp[l][h]!=-1){
        return dp[l][h];
    }
    if(l>h) return INT_MAX;
    if(l==h) return 0;
    if(l==h-1){
        dp[l][h] = (a[l]==a[h])?0:1;
        return dp[l][h];
    }
    dp[l][h] = (a[l]==a[h])?ans(a,l+1,h-1):(min(ans(a,l+1,h),ans(a,l,h-1))+1);
    return dp[l][h];
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    int n= a.size();
	    memset(dp,0,sizeof(dp));
	    //cout<<ans(a,0,n)<<"\n";
	    int gap,i,l,h;
	    for(gap=1;gap<n;gap++){
	        for(l=0,h=gap;h<n;l++,h++){
	            dp[l][h] = (a[l]==a[h])?dp[l+1][h-1]:(min(dp[l+1][h],dp[l][h-1])+1);
	        }
	    }
	    cout<<dp[0][n-1]<<"\n";
	}
	return 0;
}