#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    string arr[n];
	    int mini = INT_MAX;
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	        mini = min(mini, (int)arr[i].length());
	    }
	    string ans = "";
	    for(int j=0;j<mini;j++) {
	        int flag = 1;
	        int c = arr[0][j];
	        for(int i=1;i<n;i++) {
	            if(arr[i][j]!=c) {
	                flag = 0;
	                break;
	            }
	        }
	        if(!flag)
	            break;
	        ans.push_back(c);
	    }
	    (ans.size()!=0)?cout<<ans<<"\n":cout<<"-1\n";
	}
	return 0;
}