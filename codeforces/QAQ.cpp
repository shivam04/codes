#include <iostream>
using namespace std;

int main() {
	int i,j;
	string a;
	string b = "QAQ";
	cin>>a;
	int m= a.length();
	int n=b.length();
	int dp[m+5][n+5];
	for(i=0;i<=n;i++){
		dp[0][i] = 0;
	}
	for(i=0;i<=m;i++){
		dp[i][0] = 1;
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout<<dp[m][n]<<"\n";
	return 0;
}