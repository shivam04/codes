int mod = 1000000007;
class TrieNode {
    public:
    TrieNode* one;
    TrieNode* zero;
    long zc;
    long oc;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->one = nullptr;
    node->zero = nullptr;
    node->zc = 0;
    node->oc = 0;
    return node;
}

void insert(TrieNode* start, int n) {
    TrieNode* cur;
    cur = start;
    for(int i=31;i>=0;i--) {
        int bit = (n>>i)&1;
        if(bit==0) {
            cur->zc++;
            if(cur->zero == nullptr)
                cur->zero = getNode();
            cur = cur->zero;
        } else {
            cur->oc++;
            if(cur->one == nullptr)
                cur->one = getNode();
            cur = cur->one;
        }
    }
}
long query(TrieNode* root, int n, int k) {
    long ans = 0;
    for(int i=31;i>=0;i--) {
        int bit = (n>>i)&1;
        int Bbit = (k>>i)&1;
        if(Bbit) {
            if(bit) {
                ans += root->oc;
                if(root->zero == nullptr)
                    return ans;
                root = root->zero;
            } else {
                ans += root->zc;
                if (root->one == nullptr)
                    return ans;
                root = root->one;
            }
        } else {
            if(bit) {
                if(root->one == nullptr)
                    return ans;
                root = root->one;
            } else {
                if (root->zero == nullptr)
                    return ans;
                root = root->zero;
            }
        }
    }
    return ans;
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    TrieNode* root = getNode();
    long ans = 0;
    int cX = 0;
    insert(root, 0);
    for(int i=0;i<n;i++) {
        int x = A[i];
        cX ^= x;
        ans = (ans%mod + query(root,cX,B)%mod)%mod;
        insert(root, cX);
    }
    return ans;
}
