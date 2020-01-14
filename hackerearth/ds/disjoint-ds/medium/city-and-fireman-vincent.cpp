#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void initialize(int Arr[], int size[], int N){
    int i;
    for(i=0;i<=N;i++){
        size[i] = 1;
        Arr[i] = i;
    }
}
int root(int Arr[ ],int i)
{
    while(Arr[ i ] != i)           //chase parent of current element until it reaches root
    {
     i = Arr[ i ];
    }
    return i;
}
void unions(int Arr[ ],int size[ ],int mini[],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
        mini[root_B] = min(mini[root_B],mini[root_A]);
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
        mini[root_A] = min(mini[root_B],mini[root_A]);
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n+1],size[n+1];
    int mini[n+1];
    initialize(arr,size,n);
    int e[n+1];
    int i;
    for(i=1;i<=n;i++){
        cin>>e[i];
        mini[i] = e[i];
    }
    int k;
    cin>>k;
    int a,b;
    for(i=0;i<k;i++){
        cin>>a>>b;
        unions(arr,size,mini,a,b);
    }
    int f[n+1];
    memset(f,0,sizeof(f));
    for(i=1;i<=n;i++){
        if(mini[root(arr,i)]==e[i]){
            f[root(arr,i)]++;
        }
    }
    
    int ans = 1;
    for(i=1;i<=n;i++){
        if(f[i]>0){
            ans= (ans%mod*f[i]%mod)%mod;
        }
    }
    
    cout<<ans;
    return 0;
}
