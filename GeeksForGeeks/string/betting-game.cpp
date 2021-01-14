#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    cin>>s;
	    int n = s.length();
	    int sum = 4;
	    int bet = 1;
	    for(int i=0;i<n;i++) {
	        if(sum < bet) {
	            sum = -1;
	            break;
	        }
	        if(s[i]=='W') {
	            sum += bet;
	            bet = 1;
	        } else {
	            sum-=bet;
	            bet*=2;
	        }
	       
	    }
	    cout<<sum<<"\n";
	}
	return 0;
}