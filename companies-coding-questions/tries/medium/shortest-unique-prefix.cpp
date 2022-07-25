class TrieNode {
    public:
    unordered_map<char, TrieNode*> next;
    int freq = 0;
};

TrieNode* getNode() {
    TrieNode* node = new TrieNode();
    node->freq = 1;
    return node;
}
void addWord(TrieNode* start,string s) {
    TrieNode* cur;
    cur = start;
    for(int i=0;i<s.length();i++) {
        char c = s[i];
        if(cur->next[c] == nullptr) {
            cur->next[c] = getNode();
        } else {
            (cur->next[c]->freq)++;
        }
        cur = cur->next[c];
    }
}

string findString(TrieNode* root, string &str, int sI, string prefix) {
    if (root == NULL)
       return "";

    if (root->freq == 1) {
        return prefix;
    }
    if(root->next[str[sI]] != nullptr)
        return findString(root->next[str[sI]], str, sI+1, prefix+str[sI]);
    return "";
}

vector<string> Solution::prefix(vector<string> &A) {
    TrieNode* root = getNode();
    root->freq = 0;
    for(string s: A) {
        addWord(root, s);
    }
    vector<string> ans;
    string prefix = "";
    for(string a: A) {
        ans.push_back(findString(root, a, 0, prefix));
    }
    return ans;
}
