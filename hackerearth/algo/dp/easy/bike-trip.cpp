#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[2][n+1];
        int i,j;
        for(i=0;i<2;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        int dp[2][n+1];
        
        int cost[2][n];
        for(i=0;i<2;i++){
            for(j=0;j<n-1;j++){
                cin>>cost[i][j];
            }
        }
        
        dp[0][0]=a[0][0];
        dp[1][0]=a[1][0];
        //cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
        for(i=1;i<n;i++){
            dp[0][i] = min(dp[0][i-1]+a[0][i],dp[1][i-1]+a[0][i]+cost[1][i-1]);
            dp[1][i] = min(dp[1][i-1]+a[1][i],dp[0][i-1]+a[1][i]+cost[0][i-1]);
           //cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
        }
        cout<<min(dp[0][n-1],dp[1][n-1])<<"\n";
    }
    return 0;
}