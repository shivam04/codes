#include <bits/stdc++.h>
using namespace std;
struct tree{
    public:
    int left,right;
}tr[100010];
 
void traverse(int n){
    if(n==0)
    return;
    cout<<n<<" ";
    traverse(tr[n].left);
    traverse(tr[n].right);
    return;
}
void initialize(){
    for(int i=0;i<100010;i++){
        tr[i].left=0;
        tr[i].right=0;
    }
}
int main()
{
    int t,n,x,y,z;
    cin>>t;
    
    while(t--){
        cin>>n;
        initialize();
        while(n--){
            cin>>x>>y>>z;
            tr[x].left = y;
            tr[x].right = z;
        }
        traverse(1);
        cout<<"\n";
    }
    return 0;
}
