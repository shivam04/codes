#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    if(a.length()!=b.length()){
	        cout<<"-1\n";
	        continue;
	    }
	    int mp[256];
	    memset(mp,0,sizeof(mp));
	    for(int i=0;i<a.length();i++){
	        mp[a[i]]++;
	    }
	    for(int i=0;i<b.length();i++){
	        mp[b[i]]--;
	    }
	    int i;
	    int flag =0;
	    for(i=0;i<256;i++){
	        if(mp[i]>0){
	            flag = 1;
	            break;
	        }
	    }
	    if(flag)
	    cout<<"-1\n";
	    else{
	        
	        int n = a.length();
	        i = n-1;
	        int j = n-1;
	        int res = 0;
	        while(i>=0){
	            while(i>=0 and a[i]!=b[j]){
	                i--;
	                res++;
	            }
	            if(i>=0){
	                i--;
	                j--;
	            }
	        }
	        cout<<res<<"\n";
	    }
	}
	return 0;
}