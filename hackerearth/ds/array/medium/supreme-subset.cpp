#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int arr[n];
	map<int,int> mp;
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	    mp[arr[i]%m]++;
	}
	sort(arr, arr+n);
	int maxi = 0;
	for(auto it : mp) {
	    maxi = max(maxi, it.second);
	}
	int f = 0;
	int mod = 0;
	vector<int> ans;
	for(int i=0;i<n;i++) {
	    if(f==0 and mp[arr[i]%m] == maxi) {
	        f = 1;
	        mod = arr[i]%m;
	        ans.push_back(arr[i]);
	    } else if(f==1 and arr[i]%m == mod) {
	        ans.push_back(arr[i]);
	    }
	}
	sort(ans.begin(), ans.end());
	cout <<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)
    	cout<<ans[i]<<" ";
    cout<<"\n";
}
