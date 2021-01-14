#include<bits/stdc++.h>
using namespace std;
int checkMirror(vector<int> tree1[], vector<int> tree2[],int n) {
    for(int p=1;p<=n;p++) {
        vector<int> t1 = tree1[p];
        vector<int> t2 = tree2[p];
        int i = 0;
        int j = t2.size()-1;
        if(t1.size() != t2.size())
            return 0;
        while(i < t1.size() and j >=0) {
            if(t1[i] != t2[j])
                return 0;
            i++;
            j--;
        }
        if(i < t1.size() || j>0) {
            return 0;
        }
    }
    return 1;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,e;
	    cin>>n>>e;
	    vector<int> t1[n+1];
	    vector<int> t2[n+1];
	    int a,b;
	    for(int i=0;i<e;i++) {
	        cin>>a>>b;
	        t1[a].push_back(b);
	    }
	    for(int i=0;i<e;i++) {
	        cin>>a>>b;
	        t2[a].push_back(b);
	    }
	   cout<<checkMirror(t1,t2,n);
	        
	}
	return 0;
}