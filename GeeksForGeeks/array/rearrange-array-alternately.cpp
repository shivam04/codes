#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i,a[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int l = 0;
	    int r= n-1;
	    int temp[n];
	    int k = 0;
	    for(i=0;i<n;i++){
	        if(i%2==0)
	        temp[k++]=a[r--];
	        else
	        temp[k++]=a[l++];
	    }
	    for(i=0;i<n;i++)
	    cout<<temp[i]<<" ";
	    cout<<endl;
	}
	return 0;
}