#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class BinaryTree {
public:
    int data,h;
    int left, right;
};
BinaryTree tree[1100];
void inorder(int i){
    if(tree[i].left!=-1)
        inorder(tree[i].left);
    cout<<tree[i].data<<" ";
    if(tree[i].right!=-1)
        inorder(tree[i].right);
}
int main() {
    int n;
    cin>>n;
    int i,a,b;
    tree[1].h = 1;
    for(i=0;i<n;i++){
        tree[i+1].data = i+1;
        cin>>a>>b;
        //cout<<tree[i+1]->data<<"\n";
       // cout<<a<<" "<<b<<"\n";
        if(a==-1)
            tree[i+1].left = -1;
        else{
            tree[i+1].left = a;
            tree[a].h = tree[i+1].h+1;
        }
        if(b==-1)
            tree[i+1].right = -1;
        else{
            tree[i+1].right = b;
           tree[b].h = tree[i+1].h+1;
        }
    }
    vector<int> f[100005];
    for(i=1;i<=n;i++){
        f[tree[i].h].push_back(i);
    }
    int t,k,r,p,j;
    cin>>t;
    while(t--){
        cin>>k;
        //cout<<k<<"\n";
        r = k;
        while(r<n){
            for(j=0;j<f[r].size();j++){
                p = f[r][j];
                int temp = tree[p].left;
                tree[p].left = tree[p].right;
                tree[p].right = temp;
            }
            r+=k;
        }
        inorder(1);
        cout<<"\n";
    }
    return 0;
}
