#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,m;
	cin>>t;
	string s;
	while(t--){
	    cin>>n>>m;
	    int l= n;
	    int r = m;
	    cin>>s;
	    int flag = 0;
	    for(int i=1;i<=l;i++){
	        for(int j=1;j<=r;j++){
	            flag = 0;
	           // l =i;
	           // r =j;
	            n=i;
	            m=j;
	            for(int k=0;k<s.length();k++){
        	        if(s[k]=='L'){
        	            if(m-1<1){
        	                flag = 1;
        	                break;
        	            }
        	            m--;
        	        }else if(s[k]=='R'){
        	            if(m+1>r){
        	                flag=1;
        	                break;
        	            }
        	            m++;
        	        }else if(s[k]=='U'){
        	            if(n-1<1){
        	                flag=1;
        	                break;
        	            }
        	            n--;
        	        }else{
        	            if(n+1>l){
        	                flag=1;
        	                break;
        	            }
        	            n++;
        	        }
        	   }
        	  // cout<<i<<" "<<j<<" "<<flag<<"\n";
        	   if(flag==0)
        	   break;
        	   
	        }
	        if(flag==0)
	        break;
	    }
	    
	    if(!flag)
	    cout<<"safe\n";
	    else
	    cout<<"unsafe\n";
	    
	}
	return 0;
}
