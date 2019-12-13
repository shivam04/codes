#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	unordered_map<int,int> ump;
	map<int,int> emp;
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	    ump[arr[i]]++;
	    
	}
	
	for(int i=0;i<n;i++) {
	    int x = ump[arr[i]];
	    if(emp.find(x) == emp.end()) {
	        emp[x] = arr[i];
	    }
	}
	vector<int,int> p;
	
	for(auto it = emp.begin(); it != emp.end(); ++it) {
	    p.push_back(it->first);
	}
	
	int q;
	cin>>q;
	while(q--) {
	    int t, f;
	    cin>>t>>f;
	    if(t==0) {
	        int k = upper_bound(p.begin(), p.end(), f) - p.begin();
	        if(k>0 and p[k-1] == f) {
	            k--;
	        }
	        cout<<emp[p[k]]<<"\n";
	    } else {
	        cout<<emp[f]<<"\n";
	    }
	}
}
