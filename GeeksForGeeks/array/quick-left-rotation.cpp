#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n+1];
	    int i;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    k = k%n;
	    reverse(a,a+k);
	    reverse(a+k,a+n);
	    reverse(a,a+n);
	    for(i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}