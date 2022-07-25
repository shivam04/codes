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

int findString(TrieNode* start, string str, int sI, bool isChangeDone) {
    if(sI==str.length()) {
		return (start != nullptr and start->isWord and isChangeDone);
	}
	if(start->next.find(str[sI]) != start->next.end() and start->next[str[sI]] != nullptr) {
		int ans = findString(start->next[str[sI]], str, sI+1, isChangeDone);
        char  p =str[sI];
        if(!isChangeDone) {
            for(auto it:start->next) {
                if(p==it.first)
                    continue;
                str[sI] = it.first;
                isChangeDone = true;
                ans = ans | findString(start->next[str[sI]], str, sI + 1, isChangeDone);
            }
        }
            
        return ans;

	} else if(!isChangeDone and start!=nullptr) {
        int ans = 0;
        for(auto it:start->next) {
            str[sI] = it.first;
            isChangeDone = true;
            ans = ans | findString(start->next[str[sI]], str, sI + 1, isChangeDone);
        }
        return ans;
    }
    return 0;
}
string Solution::solve(vector<string> &A, vector<string> &B) {
    TrieNode* root = getNode();
    for(string s: A) {
        addWord(root, s);
    } 
    string ans = "";
    for(string w: B) {
        ans.push_back(findString(root, w, 0, false)+48);
    }
    return ans;
}
