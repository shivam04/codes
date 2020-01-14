#include <iostream>
using namespace std;

int main() {
	int t,n,x,l,r,f,e,i;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    int a[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    l = 0;
	    r = n;
	    f = -1;
	    int mid;
	    while(l<=r){
	        mid = (l+r)/2;
	        if(a[mid]==x){
	            f = mid;
	            break;
	        }else if(a[mid]>x){
	            r = mid-1;
	        }else{
	            f = mid;
	            l = mid+1;
	        }
	    }
	    if(f==n)
	    f--;
	    cout<<f<<"\n";
	}
	return 0;
}