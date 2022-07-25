int mod = 1000000007;
class TrieNode {
    public:
    TrieNode* one;
    TrieNode* zero;
    int idx;
    int sIdx;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->one = nullptr;
    node->zero = nullptr;
    node->idx = 0;
    node->sIdx = 0;
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
    cur->idx++;
    cur->sIdx += idx;
}
long query(TrieNode* root, int n, int idx) {
    for(int i=31;i>=0;i--) {
        int bit = (n>>i)&1;
        if(bit==0) {
            if(root->one) {
                root = root->one;
            } else {
                root = root->zero;
            }
        } else {
            if(root->zero) {
                root = root->zero;
            } else {
                root = root->one;
            }
        }
    }
    long sz = (long)root->idx;
    long sum = (long)root->sIdx;
    long ans = (sz%mod * idx%mod) - (sum%mod);
    if(ans < 0)
        ans+=mod;
    return ans;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    TrieNode* root = getNode();
    long ans = 0;
    int cX = 0;
    for(int i=0;i<n;i++) {
        int x = A[i];
        insert(root, cX, i);
        cX ^= A[i];
        ans = (ans%mod + query(root, cX, i)%mod)%mod;
    }
    return ans;
}
