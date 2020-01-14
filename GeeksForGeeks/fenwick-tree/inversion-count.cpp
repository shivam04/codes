#include<bits/stdc++.h>
using namespace std;

void update(long long BIT[], long long x, long long delta, long long n) {
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
long long query(long long BIT[], long long x) {
     long long sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}

void transform(long long temp[], long long arr[], long long n) {
    for(long long i=0;i<n;i++) {
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}

int main() {
	long long t;
	cin>>t;
	while(t--) {
	    long long n;
	    cin>>n;
	    long long arr[n];
	    long long temp[n];
	    for(long long i=0;i<n;i++) {
	        cin>>arr[i];
	        temp[i] = arr[i];
	    }
	    sort(temp, temp+n);
	    transform(temp, arr, n);
	    long long BIT[n+1];
	    memset(BIT,0,sizeof(BIT));
	    long long ans = 0;
	    for(long long i=n-1;i>=0;i--) {
	        ans += query(BIT, arr[i]-1);
	        update(BIT, arr[i], 1, n);
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}