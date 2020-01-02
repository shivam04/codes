#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int p = 0;
	while(t--) {
		p++;
		int s,q;
		cin>>s;
		string se[s+1];
		getline(cin, se[0]);
		for(int i=0;i<s;i++) {
			getline(cin, se[i]);
		}
		cin>>q;
		
		string qq[q+1];
		getline(cin, qq[0]);
		for(int i=0;i<q;i++) {
			getline(cin, qq[i]);
		}
		int ans=0;
		map<string,int> mpp;
		for(int i=0;i<q;i++) {
				mpp[qq[i]] = 1;
			if(mpp.size() == s) {
				ans++;
				mpp.clear();
				mpp[qq[i]] = 1;
			}
		}
		cout<<"Case #"<<p<<": "<<ans<<"\n";
	}
	return 0;
}