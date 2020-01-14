#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--) {
	    long long n;
	    cin>>n;
	    long long arr[n];
	    for(long long i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    long long i = 0;
	    stack<long long> s;
	    long long cnt = 0, ans = 0;
	    long long tp;
	    while(i<n) {
	        if (s.empty() || arr[s.top()] <= arr[i]) 
                s.push(i++); 
            else {
                tp = s.top();
                s.pop();
                cnt = arr[tp] * (s.empty() ? i :  
                                   i - s.top() - 1);
                ans = max(ans, cnt);
            }
	    }
	    
	    while(!s.empty()) {
	        tp = s.top();
            s.pop();
            cnt = arr[tp] * (s.empty() ? i :  
                                   i - s.top() - 1);
            ans = max(ans, cnt);
	    }
	    cout<<ans<<"\n";
	}
}
