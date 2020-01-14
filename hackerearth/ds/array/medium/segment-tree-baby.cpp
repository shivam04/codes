#include <bits/stdc++.h>
using namespace std;

int tree[270000];
int lazy[270000];
int dp[100005];

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = dp[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node] , tree[2*node+1]);
    }
}


void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        dp[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = max(tree[2*node] , tree[2*node+1]);
    }
}

void updateRange(int node, int start, int end, int l, int r, int val) {
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] +=  lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] +=  val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = max(tree[node*2] , tree[node*2+1]);        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] +=  lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return max(p1 , p2);
}

int main() {
	int n,q;
	cin>>n>>q;
	memset(dp,0,sizeof(dp));
	int l[q], r[q], v[n];
	for(int i=0;i<q;i++) {
	    //int l,r,v;
	    cin>>l[i]>>r[i]>>v[i];
	    l[i]--;
	    dp[l[i]]+=v[i];
	    dp[r[i]]-=v[i];
	    r[i]--;
	}
	for(int i=1;i<n;i++) {
	    dp[i]+=dp[i-1];
	}
	
	build(1,0,n-1);
	int ans = INT_MAX;
	for(int i=0;i<q;i++) {
	    updateRange(1,0,n-1,l[i],r[i],-1*v[i]); 
	    ans = min(ans,queryRange(1,0,n-1,0,n-1));
	    updateRange(1,0,n-1,l[i],r[i],v[i]);
	}
	cout<<ans;
	
}

