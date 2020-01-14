#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1][n+1],i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cin>>a[i][j];
    }
    int st=0,end=n-1;
    int ans = -1;
    int sum = 0;
    int maxsum = -1;
    int x1,y1,x2,y2;
    while(st<=end){
        int mid = (st+end)/2;
        sum=0;
        int flag = 0;
        for(i=0;i<n-mid+1;i++){
            for(j=0;j<n-mid+1;j++){
              sum = 0;
                for (int p=i; p<mid+i; p++)
                    for (int q=j; q<mid+j; q++)
                        sum+=a[p][q];
                //cout<<sum<<"\n";
                //cout<<i<<" "<<j<<" "<<2+i-1<<" "<<2+j-1<<"\n";
                if(sum>=k){
                    if(maxsum<sum){
                        maxsum = sum;
                        flag=1;
                        x1=i;
                        y1=j;
                        x2 = mid+i-1;
                        y2 = mid+j-1;
                    }
                    
                }
            }
        }
        if(maxsum>=k){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
    if(ans==-1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        cout<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<"\n";
    }
    return 0;
}
