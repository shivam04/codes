#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n+1];
	    unordered_set<int> s;
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	        s.insert(arr[i]);
	    }
	    int cnt = 1;
	    int maxi = 1;
	    int prev = arr[0];
	    for(int i= 0;i<n;++i) {
            if(s.find(arr[i]-1) == s.end()) {
                int j = arr[i]; 
                while (s.find(j) != s.end()) 
                    j++;
                maxi = max(maxi,j-arr[i]);
  
            }
	    }
	    cout<<maxi<<"\n";
 	}
	return 0;
}