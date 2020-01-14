#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    unordered_map<char,int> mp;
	    char a;
	    queue<char> q;
	    for(int i=0;i<n;i++) {
	        cin>>a;
	        q.push(a);
	        mp[a]++;
	        while(!q.empty()) {
	            if(mp[q.front()] > 1) {
	                q.pop();
	            } else {
	                cout<<q.front()<<" ";
	                break;
	            }
	        }
	        if(q.empty()) {
	            cout<<"-1 ";
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}