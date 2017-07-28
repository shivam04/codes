#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    int i;
	    int s[n+1];
	    int c=0;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        if(a[i]==1){
	            s[i]=-1;
	            c++;
	        }
	        
	        else
	        s[i]=1;
	    }
	    if(c==n)
	    {
	        cout<<n<<"\n";
	        continue;
	    }
	    int cmax,smax;
	    cmax = smax = s[0];
	    for(i=1;i<n;i++){
	        cmax = max(s[i],cmax+s[i]);
	        smax = max(cmax,smax);
	    }
	    cout<<smax+c<<"\n";
	}
	return 0;
}