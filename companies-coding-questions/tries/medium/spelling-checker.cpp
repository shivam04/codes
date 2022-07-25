class TrieNode {
	public:
    map<char, TrieNode*> next;
    bool isWord;
	string word;
};

TrieNode* getNode() {
	TrieNode* node = new TrieNode();
	node->isWord = false;
	node->word = "";
	return node;
}
void addWord(TrieNode* start,string s) {
	TrieNode* cur;
	cur = start;
	for(int i=0;i<s.length();i++) {
		char c = s[i];
		if(cur->next[c] == nullptr) {
			cur->next[c] = getNode();
		}
		cur = cur->next[c];
	}
	cur->isWord = true;
	cur->word = s;
}

int findString(TrieNode* start, string str, int sI) {
    if(sI==str.length()) {
		return start->isWord;
	}
	if(start->next[str[sI]] != nullptr) {
		return findString(start->next[str[sI]], str, sI+1);
	}
    return 0;
}
vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    TrieNode* root = getNode();
    for(string s: A) {
        addWord(root, s);
    } 
    vector<int> ans;
    for(string w: B) {
        ans.push_back(findString(root, w, 0));
    }
    return ans;
}
