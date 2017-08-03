#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m,o;
	    cin>>m>>n>>o;
	    string x,y,z;
	    cin>>x>>y>>z;
	    int dp[m+1][n+1][o+1];
 
        for (int i=0; i<=m; i++)
        {
            for (int j=0; j<=n; j++)
            {
                for (int k=0; k<=o; k++)
                {
                    if (i == 0 || j == 0||k==0)
                        dp[i][j][k] = 0;
     
                    else if (x[i-1] == y[j-1] && x[i-1]==z[k-1])
                        dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
     
                    else
                        dp[i][j][k] = max(max(dp[i-1][j][k],
                                             dp[i][j-1][k]),
                                         dp[i][j][k-1]);
                }
            }
        }
        cout<<dp[m][n][o]<<"\n";
	}
	return 0;
}