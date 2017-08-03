#include <bits/stdc++.h>
using namespace std;
int check(int a[],int n,int k){
    if(k==0)
    return 1;
    if(n<=0 and k!=0)
    return 0;

    
    return check(a,n-1,a[n]%k) || check(a,n-1,k);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b;
	    cin>>a>>b;
	    int i;
	    int arr[a+1];
	    for(i=0;i<a;i++){
	        cin>>arr[i];
	    }
	    int max_ele = arr[0];
        for (int i=1; i<a; i++)
            if (arr[i] > max_ele)
                max_ele = arr[i];
	    int m = (1 << (int)(log2(max_ele) + 1) ) - 1;
	    int dp[a+1][m+1];
	    
	    if(a<=0)
	    cout<<"0\n";
	    else{
	        memset(dp,0,sizeof(dp));
	        int j;
	        dp[0][0]=1;
	        for(i=1;i<=a;i++){
	            for(j=0;j<=m;j++){
	                dp[i][j] = dp[i-1][j] + dp[i-1][arr[i-1]^j];
	                
	            }
	        }
	        cout<<dp[a][b]<<"\n";
	    }
	}
	return 0;
}