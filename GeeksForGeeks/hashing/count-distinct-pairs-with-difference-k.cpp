#include<bits/stdc++.h>
using namespace std;
#define MAX 20000
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    int i;
	    map<int,int> mp;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	       mp[a[i]]++;
	    }
	    int k;
	    cin>>k;
	    if(k==0){
	        int c=0;
	        for(i=0;i<n;i++){
	            if(mp[a[i]]>=2){
	                c++;
	                mp[a[i]]-=2;
	            }
	        }
	        cout<<c<<"\n";
	        continue;
	        
	    }
	    int c=0;
	    for(i=0;i<n;i++){
	        int dd = a[i]-k;
	        int pp = a[i]+k;
	        if(mp[dd]>=1){
	            
	            c++;
	        }
	        if(mp[pp]>=1){
	            c++;
	        }
	        mp[a[i]]=0;
	    }
	    cout<<c<<"\n";
	}
	return 0;
}