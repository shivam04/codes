#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int arr[n+1];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    int i = 0;
	    int ans = 0;
	    while(i < n) {
	        int j = i + 1;
	        while(j<n) {
	            if(arr[j] < arr[j-1]) {
	                j--;
	                break;
	            }
	            j++;
	        }
	        if(j<n and j!=i) {
	            int k = j+1;
	            int f = 1;
	            int w = j+j-i;
	            if(w>=n){
	                i++;
	                continue;
	            }
	            while(k<=w and k<n) {
	                if(arr[k]>=arr[k-1]){
	                    f=0;
	                    break;
	                }
	                k++;
	            }
	            if(f) {
	                ans+=(j-i);
	                i=w;    
	            }else {
	                i++;
	            }
	            
	        } else {
	            i++;
	        }
	    }
	    cout<<ans<<"\n";
	}
}
