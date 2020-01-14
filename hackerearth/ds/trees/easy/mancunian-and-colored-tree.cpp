#include <bits/stdc++.h>
using namespace std;
int color[100005],parent[100005];
int checkancestor(int n,int c){
   // cout<<"ddd";
    if(parent[n]==-1){
        
        return -1;
    }
    //cout<<"ddsd";
    if(color[parent[n]]==c)
    return parent[n];
    //cout<<"dddsa";
    return checkancestor(parent[n],c);
}
int main()
{
    int n,c,i;
    cin>>n>>c;
    //int parent[n+1];
    parent[1] = -1;
   // vector <int> v[n+1];
    for(i=2;i<=n;i++){
        cin>>parent[i];
       // v[parent[i]].push_back(i);
    }
    //int color[n+1];
    for(i=1;i<=n;i++){
        cin>>color[i];
    }
    cout<<"-1 ";
    for(i=2;i<=n;i++){
        cout<<checkancestor(i,color[i])<<" ";
    }
    return 0;
}
