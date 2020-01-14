#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        int k;
        cin>>k;
        int i;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        deque<int> dq;
        for(i=0;i<k;i++){
            while(!dq.empty() and a[i]>=a[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
        for(;i<n;i++){
            cout<<a[dq.front()]<<" ";
            while(!dq.empty() and dq.front()<=i-k)
            dq.pop_front();
            
            while(!dq.empty() and a[i]>=a[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
        cout<<a[dq.front()]<<"\n";
    }
	return 0;
}