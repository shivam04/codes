#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<long long>a(n),re(n),in(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    in[0]=0,re[0]=0;
    int x=0,y=0;
    if(a[1]-a[0]>0)
    {x=1;in[1]=1;re[1]=1;}
    else
    {x=0;in[1]=1,re[1]=-1;}
    for(int i=2;i<n;i++)
    {
        if(x)
        {
            if(a[i]>a[i-1])
            {
                in[i-1]=y;
                in[i]=i;
                re[i]=re[i-1];
                x=1;
            }
            else
            {
                in[i-1]=i-1;
                y=i-1;
                in[i]=i;
                re[i]=re[i-1]-1;
                x=0;
            }
        }
        else
        {
            if(a[i]>a[i-1])
            {
                in[i]=i;
                in[i-1]=i-1;
                y=i-1;
                re[i]=re[i-1]+1;
                x=1;
            }
            else
            {
                in[i]=i;
                in[i-1]=y;
                re[i]=re[i-1];
                x=0;
            }   
        }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(re[r-1]-re[in[l-1]]==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}