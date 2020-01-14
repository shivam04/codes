#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    int i;
	    int z = 0;
	    int o = 0;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i]==0)
	        z++;
	        else
	        o++;
	    }
	    i=0;
	    int j = z;
	    while(i<z){
	        a[i++]=0;
	    }
	    while(j<n){
	        a[j++]=1;
	    }
	    for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}