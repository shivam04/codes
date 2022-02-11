class Solution {
public:
    int tree[300000];
    int A[100001];
    void build(int node, int start, int end)
    {
        if(start == end)
        {
            // Leaf node will have a single element
            
            tree[node] = A[start];
        }
        else
        {
            int mid = (start + end) / 2;
            // Recurse on the left child
            build(2*node, start, mid);
            // Recurse on the right child
            build(2*node+1, mid+1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

    void update(int node, int start, int end, int idx, int val)
    {
        if(start == end)
        {
            // Leaf node
            A[idx] += val;
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
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    void updateRange(int node, int start, int end, int l, int r, int val)
    {
        // out of range
        if (start > end or start > r or end < l)
            return;

        // Current node is a leaf node
        if (start == end)
        {
            // Add the difference to current node
            tree[node] += val;
            return;
        }

        // If not a leaf node, recur for children.
        int mid = (start + end) / 2;
        updateRange(node*2, start, mid, l, r, val);
        updateRange(node*2 + 1, mid + 1, end, l, r, val);

        // Use the result of children calls to update this node
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int query(int node, int start, int end, int l, int r)
    {
        if(r < start or end < l)
        {
            // range represented by a node is completely outside the given range
            return 0;
        }
        if(l <= start and end <= r)
        {
            // range represented by a node is completely inside the given range
            return tree[node];
        }
        // range represented by a node is partially inside and partially outside the given range
        int mid = (start + end) / 2;
        int p1 = query(2*node, start, mid, l, r);
        int p2 = query(2*node+1, mid+1, end, l, r);
        return (p1 + p2);
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        memset(A,0,sizeof(A));
        memset(tree,0,sizeof(tree));
        A[0] = 0;
        A[n-1]=0;
        for(int i=1;i<n-1;i++) {
            if(s[i]=='|') {
                A[i] = 0;
            } else {
                if(A[i-1] == 0 and s[i-1]=='*')
                    A[i] = 0;
                else
                    A[i] = 1;
            }
        }
        int ll[n+1];
        int rr[n+1];
        memset(ll,-1,sizeof(ll));
        memset(rr,1000000,sizeof(rr));
        ll[0] = s[0]=='|' ? 0 : -1;
        for(int i=1;i<n;i++) {
            if(s[i]=='|')
                ll[i] = max(ll[i-1], i);
            else
                ll[i] = ll[i-1];
        }
        rr[n-1] = s[n-1]=='|' ? n-1 : 1000000;
        for(int i=n-2;i>=0;i--) {
            if(s[i]=='|')
                rr[i] = min(rr[i+1], i);
            else
                rr[i] = rr[i+1];
        }
        
        build(1, 0, n-1);
        vector<int> ans;
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        for(vector<int> q: queries) {
            int l = rr[q[0]];
            int r = ll[q[1]];
            int a;
            a = query(1,0,n-1,l,r);
            ans.push_back(a);
        }
        return ans;
    }
};