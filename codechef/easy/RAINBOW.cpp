#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,i,j;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n+1][n+1];
	    
	    for(i=1;i<=n;i++){
	        for(j=1;j<=n;j++){
	            cin>>a[i][j];
	        }
	    }
	   
	    set<int> v;
	    for(i=1;i<=n;i++){
	        v.insert(i);
	    }
	   // cout<<"FF "<<v.size()<<"\n";
	    int flag = 0;
	    int f = 0;
	    while(!v.empty()){
	       // cout<<v.size()<<"\n";
	        if(v.size()<=2){
	            cout<<"0\n";
	            f = 1;
	            break;
	        }
	        flag = 0;
	        for(int i : v){
    	        set<int> val;
    	        for(int j : v){
    	            if(i==j)
    	            continue;
    	            val.insert(a[i][j]);
    	        }
    	        if(val.size()<=1){
    	            v.erase(i);
    	            flag = 1;
    	        }
    	        
	        }
	        //cout<<"ll "<<v.size()<<"\n";
	        if(!flag)break;
	    }
	    if(f==0)
	    cout<<v.size()<<"\n";
	}
	return 0;
}
