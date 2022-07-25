class TrieNode {
	public:
    map<char, TrieNode*> next;
    bool isWord;
    int freq;
};

TrieNode* getNode() {
	TrieNode* node = new TrieNode();
	node->isWord = false;
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
	cur->isWord = true;
}
int findString(TrieNode* start, string str, int sI) {
    if(sI==str.length()) {
		return start->freq;
	}
	if(start->next[str[sI]] != nullptr) {
		return findString(start->next[str[sI]], str, sI+1);
	}
    return 0;
}
vector<int> Solution::solve(vector<int> &A, vector<string> &B) {
    TrieNode* root = getNode();
    vector<int> ans;
    root->freq = 0;
    for(int i=0;i<A.size();i++) {
        if(A[i] == 0) {
            addWord(root, B[i]);
        } else {
            ans.push_back(findString(root, B[i], 0));
        }
    }
    return ans;
}
