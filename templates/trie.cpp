#include <vector>
using namespace std;
class TrieNode {
	public:
    map<char, TrieNode*>next;
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

void findString(TrieNode* start, string str, int sI, 
								unordered_set<string> &hasString) {
	if(start->isWord) {
		hasString.insert(start->word);
	}
	if(start->next[str[sI]] != nullptr) {
			findString(start->next[str[sI]], str, sI+1, hasString);
	}
}

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {
  TrieNode* start = getNode();
	for(int i=0;i<smallStrings.size();i++) {
		addWord(start, smallStrings[i]);
	}
	unordered_set<string> hasString;
	for(int i=0; i<bigString.length();i++) {
		findString(start, bigString, i, hasString);
	}
	vector<bool> ans;
	for(auto s: smallStrings) {
		ans.push_back(hasString.find(s) != hasString.end());
	}
  return ans;
}
