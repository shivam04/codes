#include<bits/stdc++.h>
using namespace std;

long long invCountUtil(long long arr[], int l, int midi, int r) {
    long long temp[r-l+1];
    int i = l;
    int j = midi;
    long long ans = 0;
    int k = 0;
    while(i<=midi-1 and j<=r) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            ans = ans + (midi-i);
         }
    }
    while(i<=midi-1) {
        temp[k++] = arr[i++];
    }
    while(j<=r) {
        temp[k++] = arr[j++];
    }
    for(int i=0;i<k;i++) {
        arr[l+i] = temp[i];
    }
    return ans;
}

long long invCount(long long arr[], int l, int r) {
    if(l>=r)
        return 0;
    int midi = (l+r)/2;
    long long p = invCount(arr,l,midi);
    long long q = invCount(arr,midi+1,r);
    return p+q+invCountUtil(arr,l,midi+1,r);
}

int main() {
	long long t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    long long arr[n];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    long long ans = invCount(arr,0,n-1);
	    cout<<ans<<"\n";
	}
	return 0;
}