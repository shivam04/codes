#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n+1];
	    int i;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    i=0;
	    int j = n-1;
	    while(i<j){
	        cout<<a[j--]<<" ";
	        cout<<a[i++]<<" ";
	    }
	    if(n%2==1){
	        cout<<a[i];
	    }
	    cout<<"\n";
	}
	return 0;
}