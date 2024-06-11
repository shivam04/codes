#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> num(n);
		for(int i=0;i<n;i++) {
			cin>>num[i];
		}
		sort(num.begin(), num.end());

		int ans = INT_MAX;
		for (int i=0;i<n-1;i++) {
			ans = min(ans, num[i]^num[i+1]);
		}
		cout<<ans<<"\n";
	}
}
