class Solution {
public:
    bool visit[7][7];
    int dirx[4] = {1,0,-1,0};
    int diry[4] = {0,1,0,-1};
    bool isValid(int i,int j, int m, int n) {
        return (i>=0 and i<m and j>=0 and j<n);
    }
    bool isExist(vector<vector<char>>& board, int i, int j, int m, int n, string w, string word) {
        visit[i][j] = true;
        w += board[i][j];
        if (w == word) {
            return true;
        }
        for(int d=0;d<4;d++) {
            int x = dirx[d]+i;
            int y = diry[d]+j;
            if (isValid(x,y,m,n) and !visit[x][y] and board[x][y] == word[w.length()]) {
                if (isExist(board, x, y, m, n, w, word)) {
                    return true;
                }
            }
        }
        w.pop_back();
        visit[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        memset(visit,false,sizeof(visit));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == word[0]) {
                    if(isExist(board,i,j,m,n,"",word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};