#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    //cout<<m<<" "<<n<<"\n";
	    int a[m][n];
	    int i;
	    int j;
	    for(i=0;i<m;i++){
	        for(j=0;j<n;j++){
	            cin>>a[i][j];
	         //   cout<<a[i][j]<<" ";
	        }
	       // cout<<"\n";
	    }
	    int l = 0;
	    int r = n-1;
	    int flag = 0;
	    int x;
	    cin>>x;
	    while(l<m and r>=0){
	        //cout<<a[l][r]<<" "<<x<<"\n";
	        if(a[l][r]==x){
	            flag = 1;
	            break;
	        }
	        else if(a[l][r]<x){
	            l++;
	        }else{
	            r--;
	        }
	    }
	    cout<<flag<<"\n";
	}
	return 0;
}