#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    string X,Y;
	    cin>>n>>m;
	    cin>>X;
	    cin>>Y;
	    int i,j;
	    int result = 0;
	    int LCS[n+1][m+1];
	    for(i=0;i<=n;i++){
		        for(j=0;j<=m;j++){
		            if(i==0 || j==0){
		                LCS[i][j] = 0;
		                continue;
		            }
		                 
	                else if(X[i-1]==Y[j-1]){
		                LCS[i][j] = LCS[i-1][j-1]+1;
		                result = max(LCS[i][j],result);
		            }
		            else LCS[i][j]=0;
		        }
		    }
		    cout<<result<<"\n";
	}
	return 0;
}