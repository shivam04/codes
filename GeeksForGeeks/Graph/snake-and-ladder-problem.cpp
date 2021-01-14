#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    unordered_map<int, int> mp;
	    int a,b;
	    for(int i=0;i<n;i++) {
	        cin>>a>>b;
	        mp[a] = b;
	    }
	    queue<int> q;
	    q.push(1);
	    int distance[31];
	    memset(distance,100,sizeof(distance));
	    distance[1] = 0;
	    while(!q.empty()) {
	        int s = q.front();
	        q.pop();
	        for(int i=1;i<=6;i++) {
	            int t = s+i;
	            if(t<=30) {
	                if(mp.find(t) != mp.end() and distance[mp[t]] > distance[s]+1) {
	                    q.push(mp[t]);
	                    distance[mp[t]] = distance[s]+1;
	                } else if(distance[t] > distance[s]+1) {
	                    q.push(t);
	                    distance[t] = distance[s]+1;
	                }
	            }
	        }
	    }
	    cout<<distance[30]<<"\n";
	}
	return 0;
}