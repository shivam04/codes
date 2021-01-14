#include<bits/stdc++.h>
using namespace std;
#define NOT_IN_STACK 0
#define IN_STACK 1
bool dfs(int v, map<pair<int,int>, int> mp, int label[], int instack_count, int n){
        if(instack_count == n)
            return true;
        for(int i=0; i<n; i++)
            if(mp[{v,i}]==1 && label[i] == NOT_IN_STACK){
                label[i]=IN_STACK;
                if(dfs(i, mp, label, instack_count+1, n))
                    return true;
                label[i]=NOT_IN_STACK;
            }
        return false;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    map<pair<int,int>, int> mp;
	    int a,b;
	    vector<int>v;
        for(int i=0; i<n; i++)
            v.push_back(i);
	    for(int i=0;i<m;i++) {
	        cin>>a>>b;
	        a--;
	        b--;
	        mp[{a,b}]=1;
	        mp[{b,a}]=1;
	    }
	    int valid = 0;
	    int label[11];
	    for(int i=0; i<n; i++)
            label[i]=NOT_IN_STACK;
        for(int i=0; i<n; i++){
            label[i]=IN_STACK;
            if(dfs(i, mp, label, 1, n)) {
                valid=1;
                break;
            }
            label[i]=NOT_IN_STACK;
        }
        cout<<valid<<"\n";
	}
	return 0;
}