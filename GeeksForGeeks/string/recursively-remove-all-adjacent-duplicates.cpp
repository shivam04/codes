#include<bits/stdc++.h>
using namespace std;
string removeA(string s) {
    if(s.size()<=1)
        return s;
    int f = 0;
    int n = s.size();
    string temp = "";
    for(int i=0;i<n;i++) {
        int j = i;
        int p = 0;
        while(j < n and s[j] == s[j+1]) {
            f = 1;
            p = 1;
            j++;
        }
        if(p) {
            i = j;
            continue;
        }
        temp += s[i];
    }
    if(f)
        return removeA(temp);
    return temp;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    cout<<removeA(s)<<"\n";
	}
	return 0;
}