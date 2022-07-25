class TrieNode {
    public:
    TrieNode* one;
    TrieNode* zero;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->one = nullptr;
    node->zero = nullptr;
    return node;
}

void insert(TrieNode* start, int n) {
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
}

int maxXor(TrieNode* root, int n) {
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
    return ans;
}

int Solution::solve(vector<int> &A) {
    TrieNode* root = getNode();
    for(int n: A) {
        insert(root, n);
    }
    int ans = -1;
    for(int n: A) {
        ans = max(ans, maxXor(root, n));
    }
    return ans;   
}
