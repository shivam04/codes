#include <bits/stdc++.h>
using namespace std;
int tree[300005];
void build(int node, int start, int end, vector<int> &A) {
    if(start == end) {
        tree[node] = A[start];
    }
    else {
        int mid = (start + end) / 2;
        build(2*node, start, mid, A);
        build(2*node+1, mid+1, end, A);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val, vector<int> &A) {
    if(start == end) {
        A[idx] = val;
        tree[node] = val;
    }
    else {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid) {
            update(2*node, start, mid, idx, val, A);
        }
        else {
            update(2*node+1, mid+1, end, idx, val, A);
        }
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if(r < start or end < l) {
        return 100005;
    }
    if(l <= start and end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1 , p2);
}

int main() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<300005;i++) {
        tree[i] = 100005;
    }
    vector<int> arr(n);
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }


    build(1, 0, n-1, arr);
    char u;
    int x,y;
    while(q--) {
        cin>>u>>x>>y;
        if (u == 'q') {
            cout<<query(1, 0, n-1, x-1, y-1)<<"\n";
        } else {
            update(1, 0, n-1, x-1, y, arr);
        }
    }
}