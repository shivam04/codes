#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
	int q;
	cin>>q;
	int a,b;
	string s;
	int p = 1;
	while(q--){
	    string s;
	    cin>>s;
	    int reda=0,redb=0,blacka=0,blackb=0,redlca=0,blacklca=0,ta,tb;
	    if(s=="Qi"){
	       p=1-p;
	       continue;
	    }else{
	        cin>>a>>b;
	    }
	    if(p==1){
	        //cout<<a<<" "<<b<<"\n";
	        ta = (int)log2f(a)+1;
	        tb = (int)log2f(b)+1;
	        //cout<<ta<<" "<<tb<<"\n";
	        if(ta%2==0){
	            if(s=="Qr"){
	                reda = ta/2;
	            }else{
	                blacka = ta/2;
	            }
	        }else{
	            //cout<<"g\n";
	            if(s=="Qr"){
	                reda = (ta-1)/2;
	            }else{
	                blacka = (ta-1)/2+1;
	            }
	        }
	        //cout<<tb<<"\n";
	        if(tb%2==0){
	            if(s=="Qr"){
	                redb = tb/2;
	            }else{
	                blackb = tb/2;
	            }
	        }else{
	           // cout<<"g\n";
	            if(s=="Qr"){
	                redb = (tb-1)/2;
	            }else{
	                blackb = (tb-1)/2+1;
	            }
	        }
	       // cout<<reda<<" "<<blacka<<" "<<redb<<" "<<blackb<<"\n";
	        int k1 = a<b?a:b;
	        int k2 = (a+b)-k1;
	        unordered_set<int> se;
	        while(k1>0){
	            se.insert(k1);
	            k1/=2;
	        }
	        int lcs=0;
	        while(k2>0){
	            if(se.count(k2)>0){
                    lcs = k2;
                    break;
	            }else{
	                k2/=2;
	            }
	        }
	        int tlca = (int)log2f(lcs)+1;
	        if(tlca%2==0){
	            if(s=="Qr"){
	                redlca = tlca/2;
	            }else{
	                blacklca = tlca/2;
	            }
	        }else{
	            if(s=="Qr"){
	                redlca = (tlca-1)/2;
	            }else{
	                blacklca = (tlca-1)/2+1;
	            }
	        }
	        int ans = 0;
	        if(s=="Qr"){
	            ans = reda + redb -2*redlca;
	            if(tlca%2==0)
	            ans++;
	        }else{
	            ans = blacka + blackb -2*blacklca;
	            if(tlca%2==1)
	            ans++;
	        }
	        cout<<ans<<"\n";
	    }
	    else{
	        ta = (int)log2f(a)+1;
	        tb = (int)log2f(b)+1;
	        if(ta%2==0){
	            if(s=="Qr"){
	                reda = ta/2;
	            }else{
	                blacka = ta/2;
	            }
	        }else{
	            if(s=="Qr"){
	                reda = (ta-1)/2+1;
	            }else{
	                blacka = (ta-1)/2;
	            }
	        }
	        if(tb%2==0){
	            if(s=="Qr"){
	                redb = tb/2;
	            }else{
	                blackb = tb/2;
	            }
	        }else{
	            if(s=="Qr"){
	                redb = (tb-1)/2+1;
	            }else{
	                blackb = (tb-1)/2;
	            }
	        }
	        
	        int k1 = a<b?a:b;
	        int k2 = (a+b)-k1;
	        unordered_set<int> se;
	        while(k1>0){
	            se.insert(k1);
	            k1/=2;
	        }
	        int lcs=1;
	        while(k2>0){
	            if(se.count(k2)==1){
                    lcs = k2;
                    break;
	            }else{
	                k2/=2;
	            }
	        }
	        int tlca = (int)log2f(lcs)+1;
	        if(tlca%2==0){
	            if(s=="Qr"){
	                redlca = tlca/2;
	            }else{
	                blacklca = tlca/2;
	            }
	        }else{
	            if(s=="Qr"){
	                redlca = (tlca-1)/2+1;
	            }else{
	                blacklca = (tlca-1)/2;
	            }
	        }
	        int ans = 0;
	        if(s=="Qr"){
	            ans = reda + redb -2*redlca;
	            if(tlca%2==1)
	            ans++;
	        }else{
	            ans = blacka + blackb -2*blacklca;
	            if(tlca%2==0)
	            ans++;
	        }
	        cout<<ans<<"\n";
	    }
	    
	}
	return 0;
}
