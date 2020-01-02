#include <bits/stdc++.h>
using namespace std;
int MODULO = 10000;
int main() {
	fstream fout,fin;
    fin.open("C-large-practice.txt",ios::in);
    fout.open("C-large-practice-output.txt",ios::out);
	int t;
	fin>>t;
	string a;
	getline(fin,a);
	for(int c=1;c<=t;c++) {
		
		getline(fin,a);
		string b = "welcome to code jam";
		//fout<<b<<"\n";
		int n = a.length();
		int m = b.length();
		int dp[m+1][n+1];
		memset(dp,0,sizeof(dp));
		
		for(int i=0;i<=m;i++) {
			dp[i][0] = 0;
		}
		for(int i=0;i<=n;i++) {
			dp[0][i] = 1;
		}
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				if(b[i-1]==a[j-1]) {
					dp[i][j] +=  (dp[i-1][j-1] + dp[i][j-1]);
				} else {
					dp[i][j] += dp[i][j-1];
				}
				dp[i][j]%=MODULO;
			}
		}
		string ans = to_string(dp[m][n]);
		int p = 4 - ans.length();
		for(int k=0;k<p;k++) {
			ans = '0' + ans;
		}
		fout<<"Case #"<<c<<": "<<ans<<"\n";
		
		
	}
	return 0;
}