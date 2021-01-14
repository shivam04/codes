#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]; // 2D matrix
bool isPal(string s, int i, int j)
{
    if (i > j)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (s[i] != s[j])
        return dp[i][j] = 0;
 
    return dp[i][j] = isPal(s, i + 1, j - 1); 
}
int countSubstrings(string s)
{
    memset(dp, -1, sizeof(dp));
    int n = s.length();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (isPal(s, i, j))
                count++;
        }
    }
    return count;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<countSubstrings(s)<<"\n";
	}
	return 0;
}