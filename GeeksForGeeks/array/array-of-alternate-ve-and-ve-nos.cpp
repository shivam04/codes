#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int i,j;
	    int a[n+1];
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    vector<int> pos;
	    vector<int> neg;
	    for(i=0;i<n;i++){
	        if(a[i]<0){
	            neg.push_back(a[i]);
	        }else{
	            pos.push_back(a[i]);
	        }
	    }
	     i=0,j=0;
	    int flag = 0;
	    while(i<pos.size() and j<neg.size()){
	        if(!flag){
	            cout<<pos[i]<<" ";
	            i++;
	            flag = 1-flag;
	        }else{
	            cout<<neg[j]<<" ";
	            j++;
	            flag = 1-flag;
	        }
	    }
	    while(i<pos.size()){
	        cout<<pos[i]<<" ";
	        i++;
	    }
	    while(j<neg.size()){
	        cout<<neg[j]<<" ";
	        j++;
	    }
	    cout<<"\n";
	}
	return 0;
}