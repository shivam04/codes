#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    int i;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    //int mini = a[0];
	    int mini_i = 0;
	    for(i=1;i<n;i++){
	        if(a[i-1]>a[i]){
	            mini_i = i;
	            break;
	        }
	    }
	    cout<<mini_i<<"\n";
	}
	return 0;
}