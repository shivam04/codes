#include <bits/stdc++.h>
using namespace std;
vector<int> computeZArray(string s) {
	int n = s.length();
    vector<int> Z(n,0);
    int L = 0, R = 0;
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
    return Z;
}
vector<int> createLPSArray(string a) {
	int n = a.length();
	vector<int> lps(n,0);
    int len = 0;
    int i = 1;
    while(i<n) {
        if(a[len]==a[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len>0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
	return lps;
}
int main() {
	string s;
	cin>>s;
	string r = s;
	reverse(r.begin(), r.end());
	vector<int> lps = createLPSArray(s+"#"+r);
	int p = lps[2*s.length()];
	lps = createLPSArray(r+"#"+s);
	int q = lps[2*s.length()];
	string newS = r.substr(0,q) + s.substr(0,p);
	cout<<newS<<"\n";
	vector<int> zarr = computeZArray(newS);
	int n = zarr.size();
	vector<int> dp(n+1,0);
	for(int i=1;i<n;i++) {
		dp[zarr[i]]++;
	}
	for(int i=n-1;i>0;i--) {
		dp[i-1]+=dp[i];
	}
	for(int i=1;i<=n;i++) {
		cout<<dp[i]+1<<" ";
	}
	cout<<"\n";
}