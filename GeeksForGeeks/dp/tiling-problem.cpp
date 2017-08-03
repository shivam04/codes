#include <iostream>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long dp[n+1];
	    long long i;
	    for(i=0;i<=3;i++)
	    dp[i] = i;
	    for(i=4;i<=n;i++)
	    dp[i] = dp[i-1] + dp[i-2];
	    
	    cout<<dp[n]<<"\n";
	}
	return 0;
}