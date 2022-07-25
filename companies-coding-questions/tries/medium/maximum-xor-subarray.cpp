class TrieNode {
    public:
    TrieNode* one;
    TrieNode* zero;
    pair<int,int> p;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->one = nullptr;
    node->zero = nullptr;
    return node;
}

void insert(TrieNode* start, int n, int idx) {
    TrieNode* cur;
    cur = start;
    for(int i=31;i>=0;i--) {
        int bit = (n>>i)&1;
        if(bit==0) {
            if(cur->zero == nullptr)
                cur->zero = getNode();
            cur = cur->zero;
        } else {
            if(cur->one == nullptr)
                cur->one = getNode();
            cur = cur->one;
        }
    }
    cur->p = {idx, n};
}
pair<int,TrieNode*> maxXor(TrieNode* root, int n) {
    int ans = 0;
    for(int i=31;i>=0;i--) {
        int bit = (n>>i)&1;
        if(bit==0) {
            if(root->one) {
                ans ^= (1<<i);
                root = root->one;
            } else {
                root = root->zero;
            }
        } else {
            if(root->zero) {
                root = root->zero;
                ans ^= (1<<i);
            } else {
                root = root->one;
            }
        }
    }
    return {ans, root};
}
vector<int> Solution::solve(vector<int> &A) {
    TrieNode* root = getNode();
    vector<int> prefix;
    prefix.push_back(0);
    for(int i=0;i<A.size();i++) {
        prefix.push_back(prefix.back() ^ A[i]);
    }
    int xors = 0;
    insert(root, prefix[0], 0);
    vector<int> ans;
    for(int i=1;i<prefix.size();i++) {
        auto p = maxXor(root, prefix[i]);
        int nXor = p.first;
        if(nXor > xors) {
            ans.clear();
            ans.push_back(p.second->p.first+1);
            ans.push_back(i);
            xors = nXor;
        } else if(nXor == xors) {
            int oldLen = ans[1] - ans[0];
            int newLen = i - (p.second->p.first+1);
            if(newLen < oldLen) {
                ans.clear();
                ans.push_back(p.second->p.first+1);
                ans.push_back(i);
            } else if(newLen==oldLen and i<ans[0]) {
                ans.clear();
                ans.push_back(p.second->p.first+1);
                ans.push_back(i);
            }
        }
        insert(root, prefix[i], i);
    }
    return ans;
}
