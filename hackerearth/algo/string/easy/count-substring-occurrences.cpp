#include <bits/stdc++.h>
using namespace std;
int main() {
	string p,t;
	cin>>p>>t;
	string s = p+"#"+t;
	int L = 0, R = 0;
	int n = s.length();
	vector<int> Z(n,0);
	for(int i=1;i<n;i++) {
		if(i>R) {
			L=R=i;
			while (R < n && s[R-L] == s[R]) {
				R++;
			}
			Z[i] = R-L; 
			R--;
		} else {
			int k = i-L;
			if(Z[k] < R-i+1) {
				Z[i] = Z[k];
			} else {
				L = i;
				while(R<n && s[R-L]==s[R]) {
					R++;
				}
				Z[i] = R-L;
				R--;
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += (Z[i]==p.size());
	}
	cout<<ans<<endl;
}