#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i;
	    int a[n+1];
	    int ans = 1;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    i=0;
	    int ns;
	    int s=0;
	    int y;
	    while(i<n-1){
	        while(i<n-1 and a[i]<a[i+1])
	        i++;
	        while(i<n-1 and a[i]>a[i+1]){
	            i++;
	        }
	        if(ans<i-s+1){
	            ans=i-s+1;
	            y=s;
	        }
	        s = i;
	        while(i<n-1 and a[i]==a[i+1])
	        i++;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}