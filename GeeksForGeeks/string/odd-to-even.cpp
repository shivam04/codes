#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int i;
        int p = s[n-1];
        int maxi = -1;
        for(i=0;i<n-1;i++){
            if((s[i]-48)%2==0){
                swap(s[i],s[n-1]);
                maxi=max(maxi,stoi(s));
                swap(s[i],s[n-1]);
            }
        }
        if(maxi==-1)
        maxi = stoi(s);
        cout<<maxi<<"\n";
    }
     
	return 0;
}