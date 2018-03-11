#include <bits/stdc++.h>
using namespace std;
int main() {
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
	    int ans[n+1];
	    stack<int> s;
	    s.push(0);
	    for(i=1;i<n;i++){
	        int x = a[i];
	        if(s.empty()==false){
	            int e = s.top();
	            s.pop();
	            while(a[e]<x){
	                ans[e] = x;
	                if(s.empty()==true)
	                break;
	                e = s.top();
	                s.pop();
	            }
	            if(a[e]>x)
	            s.push(e);
	        }
	        s.push(i);
	    }
	    //cout<<s.size()<<"\n";
	    while (s.empty() == false)
        {
            //cout<<a[s.top()]<<"\n";
            ans[s.top()] = -1;
            s.pop();
        }
        //ans[n-1]=-1;
        for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}