class Solution {
public:
    bool visit[202][202];
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,1,0,-1};
    bool isValid(int i, int j, int n, int m) {
        return (i>=0 and i<n and j>=0 and j < m and !visit[i][j]);
    }
    bool checkExist(vector<vector<char>>& board, int i, int j, int n, int m, string s, string word) {
        visit[i][j] = true; 
        s = s + board[i][j]; 
        if(s==word)
            return true;
        for(int d=0;d<4;d++) {
            int x = i+dirx[d];
            int y = j+diry[d];
            if(isValid(x,y,n,m) and board[x][y] == word[s.length()]) {
                bool p = checkExist(board,x,y,n,m,s,word);
                if(p)
                    return p;
            }
        }
        s.pop_back();
        visit[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();      
        memset(visit,false,sizeof(visit));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    bool p = checkExist(board, i, j, n, m, "", word); 
                    if(p)
                        return p;
                }
            }
        }
        return false;
    }
};