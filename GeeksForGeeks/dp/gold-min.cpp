#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int table[n][m];
	    int gm[n][m];
	    int i,j;
	    memset(table,0,sizeof(table));
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            cin>>gm[i][j];
	        }
	    }
	    for(i=m-1;i>=0;i--){
	        for(j=0;j<n;j++){
	            int right = (i==m-1)?0:table[j][i+1];
	            int rightup = (j==0 || i==m-1)?0:table[j-1][i+1];
	            int rightdown = (j==n-1 || i==m-1)?0:table[j+1][i+1];
	            table[j][i] = gm[j][i] + max(max(right,rightup),rightdown);
	        }
	    }
	    
	    int ans = table[0][0];
	    for(i=1;i<n;i++){
	        ans = max(table[i][0],ans);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}