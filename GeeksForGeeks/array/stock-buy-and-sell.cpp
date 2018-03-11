#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i;
        int p[n+1];
        for(i=0;i<n;i++){
            cin>>p[i];
        }
        vector<pair<int,int> > ans;
        ans.resize(n/2);
        int  c = 0;
        i=0;
        while(i<n){
            while(i<n-1 and p[i+1]<=p[i])
            i++;
            if(i==n-1)
            break;
            ans[c].first = i++;
            while(i<n and p[i]>=p[i-1])
            i++;
            ans[c].second = i-1;
            c++;
        }
        //cout<<c<<"\n";
        if(c==0){
            cout<<"No Profit\n";
        }else{
            for(int i=0;i<c;i++){
                cout<<"("<<ans[i].first<<" "<<ans[i].second<<") ";
            }
            cout<<"\n";
        }
    }
    
	return 0;
}