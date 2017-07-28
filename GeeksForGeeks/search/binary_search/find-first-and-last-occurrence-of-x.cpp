#include <iostream>
using namespace std;

int main() {
	int t,n,x;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[n+1];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cin>>x;
	    int f=-1,e=-1;
	    int l = 0,r=n;
	    int mid;
	    while(l<=r){
	        mid = (l+r)/2;
	        if(a[mid]==x){
	            f= mid;
	            r = mid-1;
	            
	        }else if(a[mid]>x){
	            r = mid-1;
	        }else{
	            l = mid + 1;
	        }
	    }
	    l = 0;r=n;
	    while(l<=r){
	        mid = (l+r)/2;
	        if(a[mid]==x){
	            e = mid;
	            l = mid +1;
	            
	        }else if(a[mid]>x){
	            r = mid-1;
	        }else{
	            l = mid + 1;
	        }
	    }
	    if(f==-1 and e==-1){
	        cout<<"-1\n";
	        continue;
	    }
	    cout<<f<<" "<<e<<"\n";
	}
	return 0;
}