#include<iostream>
using namespace std;

int main(){
    int t,r,c,R,C,flag,i,j,k,l;
    cin>>t;
    while(t--){
        cin>>R>>C;
        char a[R][C];
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                cin>>a[i][j];
               // cout<<a[i][j]<<" ";
            }
           // cout<<"\n";
        }
        cin>>r>>c;
        char b[r][c];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin>>b[i][j];
               // cout<<b[i][j]<<" ";
            }
           // cout<<"\n";
        }
        flag=0;
        int final=0;
        for(i=0;i<=R-r;i++){
           // cout<<"H";
            for(j=0;j<=C-c;j++){
                if(a[i][j]==b[0][0]){
                   // cout<<a[i][j]<<" "<<b[0][0]<<" "<<i<<" "<<j<<"\n";
                    flag=1;
                    for(k=0;k<r;k++){
                        if(flag==0)
                            break;
                        for(l=0;l<c;l++){
                            if(b[k][l]==a[i+k][j+l]){
                                if(k==r-1&&l==c-1)
                                    final=1;
                                flag=1;
                            }
                            else{
                                flag=0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(final==0)
            cout<<"NO\n";
        if(final)
            cout<<"YES\n";
    }
    return 0;
}