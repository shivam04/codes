#include <bits/stdc++.h>
using namespace std;
int maxone(vector<int> &A, int B) {
    int l=0,r=0;
    int n = A.size();
    int zC = 0;
    int si = 0;
    int maxi = 0;
    while(r<n){
        if(zC<=B){
            if(A[r]==0)
                zC++;
            r++;
        }
        if(zC>B){
            if(A[l]==0)
                zC--;
            l++;
        }
        if(r-l>maxi){
            maxi = r-l;
            si = l;
        }
    }
    return maxi;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v;
	    v.resize(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int m;
	    cin>>m;
	    cout<<maxone(v,m)<<"\n";;
	}
	return 0;
}