#include <iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int dp[n+1];
    dp[n]=0;
    int i;
    for(i=n-1;i>=0;i--){
        if((s[i]-48)%2==0)
        dp[i] = dp[i+1]+1;
        else
        dp[i]= dp[i+1];
        
    }
    for(i=0;i<n;i++)
    cout<<dp[i]<<" ";
    return 0;
}
