#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    stack<int> s;
	    string pran;
	    cin>>pran;
	    int sm;
	    	int n = pran.length();
	    sm=0;
	    int i;
	    s.push(-1);
	    for(i=0;i<n;i++){
	        if(pran[i]=='('){
	            s.push(i);
	        }else{
	            s.pop();
	            if(!s.empty()){
	                sm = max(sm,i-s.top());
	            }else{
	                s.push(i);
	            }
	        }
	    }
	    cout<<sm<<"\n";
	}
	return 0;
}