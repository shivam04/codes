#include <bits/stdc++.h>
using namespace std;
#define inf 1000000007
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,w;
	    cin>>n>>w;
	    int cost[n+1];
	    int i,j;
	    for(i=0;i<n;i++)
	    cin>>cost[i];
	    
	    vector<int> val;
	    vector<int> wt;
	    int sz = 0;
	    for(i=0;i<n;i++){
	        if(cost[i]!=-1){
	            sz++;
	            val.push_back(cost[i]);
	            wt.push_back(i+1);
	        }
	    }
	    int dp[sz+1][w+1];
	    for(i=0;i<=w;i++)
	    dp[0][i] = inf;
	    for(i=1;i<=sz;i++)
	    dp[i][0] = 0;
	    for(i=1;i<=sz;i++){
	        for(j=1;j<=w;j++){
	            if(wt[i-1]>j){
	                dp[i][j] = dp[i-1][j];
	            }else{
	                dp[i][j] = min(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
	            }
	        }
	    }
	    if(dp[sz][w]==inf)
	    cout<<-1<<"\n";
	    else
	    cout<<dp[n][w]<<"\n";
	}
	return 0;
}