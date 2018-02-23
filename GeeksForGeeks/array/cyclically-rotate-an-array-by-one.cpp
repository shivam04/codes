#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int v[n+1];
	    int i;
	    for(i=0;i<n;i++){
	        cin>>v[i];
	    }
	    reverse(v,v+n-1);
	    reverse(v,v+n);
	    for(int i=0;i<n;i++)
	    cout<<v[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}