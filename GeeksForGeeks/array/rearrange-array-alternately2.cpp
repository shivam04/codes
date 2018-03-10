#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i,a[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int l = 0;
	    int r= n-1;
	    int me = a[r]+1;
	    int k = 0;
	    for(i=0;i<n;i++){
	        if(i%2==0)
	        a[i]+=(a[r--]%me)*me;
	        else
	        a[i]+=(a[l++]%me)*me;
	    }
	    for(i=0;i<n;i++)
	    cout<<a[i]/me<<" ";
	    cout<<endl;
	}
	return 0;
}