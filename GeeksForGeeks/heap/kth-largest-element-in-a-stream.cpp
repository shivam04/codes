#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,k;
	    cin>>k>>n;
	    int a;
	    priority_queue<int, vector<int>, greater<int>> q;
	    for(int i=1;i<=n;i++) {
	        cin>>a;
	        if(i<k) {
	            cout<<"-1 ";
	            q.push(a);
	        } else if(i==k){
	            q.push(a);
	            cout<<q.top()<<" ";
	        }else {
	            int t = q.top();
	            a = max(t,a);
	            q.pop();
	            q.push(a);
	            cout<<q.top()<<" ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}