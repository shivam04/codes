#include <iostream>
using namespace std;
int m = 1e9+7;
int main() {
	int t;
	cin>>t;
	long long dp[101];
	    dp[0]=1;
	    dp[1]=1;
	    dp[2]=2;
	    for(int i=3;i<=100;i++){
	        dp[i] = (dp[i-1]%m+dp[i-2]%m)%m;
	    }
	while(t--){
	    int n;
	    cin>>n;
	    cout<<dp[n]<<"\n";
	}
	return 0;
}