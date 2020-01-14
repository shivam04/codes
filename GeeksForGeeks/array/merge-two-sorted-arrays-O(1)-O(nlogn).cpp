#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    int arr[n+1], brr[m+1];
	    for(int i=0;i<n;i++) {
	        cin>>arr[i];
	    }
	    for(int i=0;i<m;i++) {
	        cin>>brr[i];
	    }
	    int i =0,j=0;
	    int p = (n+m);
	    int g = (p/2)+(p%2);
	    cout<<g<<"\n";
	    while(g>0) {
	        int i;
	        for(i=0;i+g<n;i++) {
	            if (arr[i] > arr[i + g]) 
                    swap(arr[i], arr[i + g]); 
	        }
	        int j;
	        for(j = (g > n)?g-n:0; i<n and j<m; i++,j++) {
	            if (arr[i] > brr[j]) 
                    swap(arr[i], brr[j]); 
	        }
	        
	        if(j<m) {
    	        for(j=0;j+g<m;j++) {
    	            if (brr[j] > brr[j + g]) 
                        swap(brr[j], brr[j + g]); 
    	        }
	        }
	        if(g<=1)
	            break;
	        g = (g/2) + (g%2);
	    }
	    for(int i=0;i<n;i++) {
	        cout<<arr[i]<<" ";
	    }
	    for(int i=0;i<m;i++) {
	        cout<<brr[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}