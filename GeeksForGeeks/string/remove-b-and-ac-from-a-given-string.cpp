#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n =s.length();
	    for(int i=0;i<s.length();i++){
	        if(s[i]=='b')
	        cout<<"";
	        else if(s[i]=='a' and i+1<n and s[i+1]=='c'){
	            i++;
	            cout<<"";
	        }else{
	            cout<<s[i];
	        }
	    }
	    cout<<"\n";
	}
	return 0;
}