#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    int n = s.length();
	    int dp[n+1][n+1];
	    memset(dp,0,sizeof(dp));
	    int max_len = 1;
	    int max_i = 0;
	    for(int i=0;i<=n;i++) {
	        dp[i][i] = 1;
	    }
	    for(int i=0;i<n-1;i++) {
	        if(s[i]==s[i+1]){
	            dp[i][i+1] = 1;
	            if(max_len < 2) {
	                max_len = 2;
	                max_i = i;
	            }
	        }
	    }
	    
	    for(int len=3;len<=n;len++) {
	        for(int i=0;i<n-len+1;i++) {
	            int j = i+len-1;
	            if(s[i]==s[j] and dp[i+1][j-1]) {
	                dp[i][j] = 1;   
	                if(max_len < len) {
	                    max_len = len;
	                    max_i = i;
	                }
	            }
	        }
	    }
	    cout<<s.substr(max_i, max_len)<<"\n";
	}
	return 0;
}