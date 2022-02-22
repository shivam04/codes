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
int valid(int i,int j,int m,int n){
	if(i>=0 and i<m and j>=0 and j<n)
    return 1;
  return 0;
}
set<string> ans;
int pos[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,-1},{1,0},{1,1}};
void dfs(TrieNode* root, int i, int j, int m, int n, map<int,map<int,bool>> &vis,
				vector<vector<char>> board) {
	vis[i][j] = 1;
	if(root->isWord==true) {
		ans.insert(root->word);
	}
	for(int h=0;h<8;h++){
		int x = i+pos[h][0];
    int y = j+pos[h][1];
		if(valid(x,y,m,n) and vis[x][y]==0) {
			char ch = board[x][y];
			if(root->next[ch] != nullptr) {
				dfs(root->next[ch], x, y, m, n, vis, board);
			}
		}
	}
	vis[i][j] = 0;
}
vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
	ans.clear();
	TrieNode *start = getNode();
  for(string word: words) {
		addWord(start, word);
	}
	int m = board.size();
	int n = board[0].size();
	map<int,map<int,bool>> vis;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			char ch = board[i][j];
			if(start->next[ch] != nullptr) {
				dfs(start->next[ch], i, j, m, n, vis,board);
			}
		}
	}
	vector<string> anss(ans.begin(), ans.end());
  return anss;
}
