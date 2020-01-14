#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    //cout<<t<<"\n";
    while(t--){
        string s;
        cin>>s;
        //cout<<s<<"\n";
        int f[26],i;
        for(i=0;i<26;i++){
            f[i]=0;
        }
       
        for(i=0;i<s.length();i++){
            f[s[i]-'a']+=1;
        }
        int ans = 1;
        for(i=0;i<26;i++){
            //cout<<f[i]<<"\n";
            if(f[i]%2){
                ans = -1;
                break;
            }
        }
         //cout<<s<<"\n";
        cout<<ans<<"\n";
         //cout<<s<<"\n";
    }
    return 0;
}
