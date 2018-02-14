#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int arr[n+5],i;
	    for(i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int dp[m+2];
	    memset(dp,0,sizeof(dp));
	    if(n>m){
	        dp[0] = 1;
	    }
	    int j;
	    for(i=0;i<n;i++){
	        if(dp[0]){
	            break;
	        }
	        int temp[m+2];
	        memset(temp,0,sizeof(temp));
	        for(j=0;j<m;j++){
	            if(dp[j]==1){
    	            if(dp[(j+arr[i])%m]==0){
    	                temp[(j+arr[i])%m]=1;    
    	            }
	            }
	        }
	        for(j=0;j<m;j++){
	            if(temp[j])
	                dp[j]=1;
	        }
	        dp[arr[i]%m] = 1;
	    }
	    cout<<dp[0]<<"\n";
	}
	return 0;
}