#include <bits/stdc++.h>
using namespace std;
long long n;
#define mod 1000000007

int main() {
	
	cin>>n;
	int i;
	long long dp[n+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3;
	for(i=3;i<=n;i++){
		dp[i] = (2*dp[i-1]%mod+3*dp[i-2]%mod)%mod;
	//	cout<<dp[i]<<" ";
	}
	cout<<dp[n]<<"\n";
	return 0;
}