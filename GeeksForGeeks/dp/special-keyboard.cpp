#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i;
	    int dp[n+1];
	    for(i=0;i<=6;i++){
	        dp[i] = i;
	    }
	    int j;
	    for(i=7;i<=n;i++){
	        dp[i]=0;
	        for(j=i-3;j>=0;j--){
	            dp[i] = max(dp[i],(i-j-1)*dp[j]);
	        }
	    }
	    cout<<dp[n]<<"\n";
	}
	return 0;
}