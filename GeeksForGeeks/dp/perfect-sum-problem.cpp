#include<bits/stdc++.h>
using namespace std;
struct ssp{
    int ans;
    int count = 0;
};
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,i,j;
	    cin>>n;
	    int a[n+1];
	    for(i=1;i<=n;i++){
	        cin>>a[i];
	    }
	    int sum;
	    cin>>sum;
	    struct ssp dp[n+5][sum+5];
	    for(i=0;i<=n;i++){
	        dp[i][0].ans = 1;
	        dp[i][0].count = 1;
	    }
	    for(i=1;i<=sum;i++){
	        dp[0][i].ans = 0;
	    }
	    for(i=1;i<=n;i++){
	        for(j=0;j<=sum;j++){
	            if(j>=a[i]){
	                dp[i][j].ans = dp[i-1][j].ans || dp[i-1][j-a[i]].ans;
	                if(dp[i-1][j-a[i]].ans==1){
	                    dp[i][j].count += dp[i-1][j-a[i]].count;
	                }
	                if(dp[i-1][j].ans==1){
	                    dp[i][j].count += dp[i-1][j].count;
	                }
	            }else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    cout<<dp[n][sum].count<<"\n";
	}
	return 0;
}