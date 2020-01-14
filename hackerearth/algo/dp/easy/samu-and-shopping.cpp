#include <iostream>
using namespace std;

int main()
{
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n+1][3];
        int i;
        for(i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        int dp[n+1][4];
        for(i=1;i<=3;i++){
            dp[1][i] = a[0][i-1]; 
            //cout<<dp[1][i]<<" ";
        }
        //cout<<"\n";
        
        for(i=2;i<=n;i++){
            dp[i][1] = min(dp[i-1][2],dp[i-1][3])+a[i-1][0];
            dp[i][2] = min(dp[i-1][1],dp[i-1][3])+a[i-1][1];
            dp[i][3] = min(dp[i-1][1],dp[i-1][2])+a[i-1][2];
           // coout<<dp[i][1]
        }
        cout<<min(dp[n][1],min(dp[n][2],dp[n][3]))<<"\n";
    }
    return 0;
}
