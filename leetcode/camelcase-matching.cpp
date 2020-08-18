#define char_int(c) ((int)c - (int)'A')
map<string, bool> seen;
struct TrieNode
{
    TrieNode *next[52];
    bool word;
};
TrieNode *getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->word = false;
    for (int i =0 ; i< 52 ; i++)
        newNode->next[i] = NULL;
    return newNode;
}
void addWord(TrieNode* start,string s)
{
	TrieNode* cur;
	cur = start;
	for (int i = 0; i < s.size(); i++) {
	    int ch;
	    if(s[i]>='A' and s[i]<='Z'){
	        ch = char_int(s[i]);
	    }else{
	        ch = char_int(toupper(s[i]))+26;
	    }
		if (cur -> next[ch] == NULL) {
			cur -> next[ch] = getNode();
		}
		cur = cur -> next[ch];
	}
	cur -> word = true;
}
void dfs(TrieNode* root, string pattern, int i, string s) {
    if(root->word) {
        if(i==pattern.size()) {
            seen[s] = true;
        } else {
            seen[s] = false;
        }
        
    }
    for(int o=0;o<52;o++) {
        if(root->next[o]!=NULL){
            char ch;
            if(o<26)
                ch = 'A'+o;
            else
                ch = tolower('A'+o-26);
            if(i < pattern.size() and ch == pattern[i]) {
                dfs(root->next[o], pattern, i+1, s+ch);
            } else{
                if(isupper(ch))
                    continue;
                dfs(root->next[o], pattern, i, s+ch);
            }
        }
    }
}
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        TrieNode *root = getNode();
        for(auto q: queries) {
            addWord(root, q);
            seen[q] = false;
        }
        dfs(root, pattern, 0, "");
        vector<bool> ans;
        for(auto q: queries) {
           ans.push_back(seen[q]);
        }    
        return ans;
    }
};