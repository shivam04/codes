string ans = "";
int minL = INT_MAX;
struct TrieNode
{
    TrieNode *next[26];
    bool word;
};
TrieNode *getNode()
{
    TrieNode * newNode = new TrieNode;
    newNode->word = false;
    for (int i =0 ; i< 26 ; i++)
        newNode->next[i] = NULL;
    return newNode;
}
void addWord(TrieNode* start,string s)
{
	TrieNode* cur;
	cur = start;
	for (int i = 0; i < s.size(); i++) {
	    int ch = s[i] - 'a';
		if (cur -> next[ch] == NULL) {
			cur -> next[ch] = getNode();
		}
		cur = cur -> next[ch];
	}
	cur -> word = true;
}
bool check(TrieNode* root, int i, string s, string temp) {
    if(root->word) {
        ans = temp;
        return true;
    }
    if(i==s.length()) {
        return false;
    }
    int ch = s[i] - 'a';
    if(root->next[ch]) {
        bool p = check(root->next[ch], i+1,s, temp+s[i]);
        if(p)
            return p;
    }
    return false;
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = getNode();
        for(auto d : dictionary) {
            addWord(root, d);
        }
        istringstream iss(sentence);
        vector<string> result{ 
            istream_iterator<string>(iss), {} 
        };  
        string anss = "";
        for(auto d: result) {
            ans = "";
            minL = INT_MAX;
            bool p = false;
            p = check(root, 0, d, "");
            if(!p)
                anss = anss + d + " ";
            else
                anss = anss + ans + " ";
        }
        return anss.substr(0, anss.length()-1);
        
    }
};