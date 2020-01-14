#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int i;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<int> endindex(n,0);
	    int p = 1;
	    
	    for(i=1;i<n;i++){
	        if(a[i]<a[endindex[0]])
	        endindex[0] = i;
	        else if(a[i]>a[endindex[p-1]]){
	            endindex[p++] = i;
	        }else{
	            int l=-1;
	            int r=p-1;
	            while(r-l>1){
	                int m = (l+r)/2;
	                if(a[endindex[m]]>=a[i])
	                r = m;
	                else
	                l = m;
	            }
	            endindex[r]=i;
	        }
	    }
	    cout<<min(p,n)<<"\n";
	}
	return 0;
}