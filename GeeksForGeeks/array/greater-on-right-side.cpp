#include<iostream>
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
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int max = a[n-1];
	    a[n-1] = -1;
	    for(i=n-2;i>=0;i--){
	        int temp = a[i];
	        a[i]=max;
	        if(temp>max)
	        max = temp;
	    }
	    for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}