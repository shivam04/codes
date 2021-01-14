#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void permute(string s, int l, int r) {
    if(l==r)
        ans.push_back(s);
    for(int i=l;i<=r;i++) {
        swap(s[i], s[l]);
        permute(s, l+1, r);
        swap(s[i], s[l]);
    }
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    ans.clear();
	    permute(s, 0, s.size()-1);
	    sort(ans.begin(), ans.end());
	    for(auto s: ans) {
	        cout<<s<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}