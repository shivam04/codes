#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,sum=0;
	    cin>>n;
	    int a[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    if(sum%2==1){
	        cout<<"NO\n";
	    }else{
	        sum = sum/2;
	        int i,j;
	        bool subset[n+1][sum+1];
	        for(i=0;i<=sum;i++)
	        subset[0][i]=false;
	        for(i=0;i<=n;i++)
	        subset[i][0]=true;
	        for(i=1;i<=n;i++){
	            for(j=1;j<=sum;j++){
	                if(j<a[i-1])
	                subset[i][j] = subset[i-1][j];
	                if(j>=a[i-1])
	                subset[i][j] = subset[i-1][j] || subset[i-1][j-a[i-1]];
	            }
	        }
	        if(subset[n][sum]){
	            cout<<"YES\n";
	        }else{
	            cout<<"NO\n";
	        }
	    }
	    
	}
	return 0;
}